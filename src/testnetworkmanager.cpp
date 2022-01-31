#include "testnetworkmanager.h"

#include <QNetworkCookieJar>
#include "QtCUrl.h"

TestNetworkManager::TestNetworkManager(QObject *parent)
    : QObject(parent),
      _cookiesHandler(new CookiesHandler),
      _curlManager(new QtCurlManager) {}

TestNetworkManager::~TestNetworkManager() {}

TestNetworkManager::RequestResult TestNetworkManager::send(
    const TestNetwork::RequestPackage &package) {
  _curlManager->setPackage(package);
  if (true) {
    return SUCCESS;
  } else {
    return FAILURE;
  }
}

QtCurlManager::QtCurlManager(QObject *parent) : QObject(parent) {
  QtCUrl cUrl;
  cUrl.setTextCodec("UTF-8");
}

void QtCurlManager::setOptions() {}

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
