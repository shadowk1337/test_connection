#include "testnetworkmanager.h"

#include <QNetworkCookieJar>

TestNetworkManager::TestNetworkManager(QObject *parent) : QObject(parent) {
  _cookiesHandler = new CookiesHandler;
}

TestNetworkManager::~TestNetworkManager() {}

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
