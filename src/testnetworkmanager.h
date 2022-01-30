#ifndef TESTNETWORKMANAGER_H
#define TESTNETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QPointer>

class CookiesHandler;

class TestNetworkManager : public QObject {
  Q_OBJECT

public:
  TestNetworkManager(QObject *parent = 0);
  ~TestNetworkManager();

  enum RequestResult {
    FAILURE = 0,
    SUCCESS,
  };

public:
  RequestResult send();

private:
  CookiesHandler *_cookiesHandler;
};

class CookiesHandler : public QObject {
  Q_OBJECT

public:
  CookiesHandler(QObject *parent = 0);
  ~CookiesHandler();

public:
  void sendGetRequest(const QUrl &url, const QByteArray &data);
  void sendPostRequest(const QUrl &url, const QByteArray &data);

private:
  QNetworkAccessManager *_networkManager;
};

class QtCurlManager {
public:
  QtCurlManager();

public:
  void setOptions();
};

#endif // TESTNETWORKMANAGER_H
