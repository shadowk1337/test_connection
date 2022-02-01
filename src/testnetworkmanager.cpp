#include "testnetworkmanager.h"

#include <QDir>
#include <QNetworkCookieJar>

TestNetworkManager::TestNetworkManager(QObject *parent)
    : QObject(parent), _cookiesHandler(new CookiesHandler),
      _curlManager(new QtCurlManager) {}

TestNetworkManager::~TestNetworkManager() {}

TestNetwork::RequestResult
TestNetworkManager::send(const TestNetwork::RequestPackage &package) {
  _curlManager->setPackage(package);
  if (_curlManager->sendRequest()) {
    qDebug() << "SUCCESS";
    return TestNetwork::SUCCESS;
  } else {
    qDebug() << "FAILURE";
    return TestNetwork::FAILURE;
  }
}

QtCurlManager::QtCurlManager(QObject *parent) : QObject(parent) {
  _curl.setTextCodec("Windows-1251");
}

TestNetwork::RequestResult QtCurlManager::sendRequest() {
  return sendPostRequest() && sendGetRequest() ? TestNetwork::SUCCESS
                                               : TestNetwork::FAILURE;
}

TestNetwork::RequestResult QtCurlManager::sendPostRequest() {
  QtCUrl::Options options;
  options[CURLOPT_URL] = _package.url;
  options[CURLOPT_POST] = true;
  QUrlQuery urlQuery;
  urlQuery.addQueryItem("username", _package.login);
  urlQuery.addQueryItem("password", _package.password);
//  options[CURLOPT_POSTFIELDS] = QUrl(urlQuery.toString());
  options[CURLOPT_POSTFIELDS] = "https://account.mail.ru";
  options[CURLOPT_SSL_VERIFYHOST] = false;
  options[CURLOPT_SSL_VERIFYPEER] = false;
  options[CURLOPT_COOKIEJAR] = QDir::currentPath() + "/cookie.txt";
  options[CURLOPT_USERAGENT] = _userAgent;
  options[CURLOPT_REFERER] = "https://account.mail.ru"; // TODO
  options[CURLOPT_FOLLOWLOCATION] = false;

  QString result = _curl.exec(options);
  if (_curl.lastError().isOk()) {
    qDebug() << result;
    return TestNetwork::SUCCESS;
  } else {
    qDebug() << QString("ERROR");
    qDebug() << QString("BUFFER: %1").arg(_curl.errorBuffer());
    return TestNetwork::FAILURE;
  }
}

TestNetwork::RequestResult QtCurlManager::sendGetRequest() {
  return TestNetwork::SUCCESS;
}

void QtCurlManager::setPackage(const TestNetwork::RequestPackage &package) {
  _package = package;
}

CookiesHandler::CookiesHandler(QObject *parent)
    : QObject(parent), _networkManager(new QNetworkAccessManager(this)) {
  _networkManager->setCookieJar(new QNetworkCookieJar(this));
}

CookiesHandler::~CookiesHandler() {}

void CookiesHandler::sendGetRequest(const QUrl &url, const QByteArray &data) {
  Q_UNUSED(data)

  QNetworkRequest r(url);
  _networkManager->get(r);
}

void CookiesHandler::sendPostRequest(const QUrl &url, const QByteArray &data) {
  QNetworkRequest r(url);
  _networkManager->post(r, data);
}
