#include "testnetworkmanager.h"

TestNetworkManager::TestNetworkManager(QObject *parent)
    : QObject(parent), _networkManager(new QNetworkAccessManager()) {
  _cookiesHandler = new CookiesHandler(_networkManager);
}

TestNetworkManager::~TestNetworkManager() {}

CookiesHandler::CookiesHandler(QNetworkAccessManager *networkManager,
                               QObject *parent)
    : QObject(parent), _networkManager(networkManager) {}

CookiesHandler::~CookiesHandler() {}

void CookiesHandler::sendGetRequest(const QUrl &url, const QByteArray &data) {}

void CookiesHandler::sendPostRequest(const QUrl &url, const QByteArray &data) {}
