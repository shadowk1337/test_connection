#ifndef TESTNETWORKMANAGER_H
#define TESTNETWORKMANAGER_H

#include "QtCUrl.h"

#include <QNetworkAccessManager>
#include <QPointer>
#include <QStringList>
#include <QUrlQuery>

class QtCurlManager;
class CookiesHandler;

QT_BEGIN_NAMESPACE
namespace TestNetwork {
// enum CurlOptions {
//  CURLOPT_POST = 0,  // bool
//  CURLOPT_FOLLOWACTION,
//  CURLOPT_FAILONERROR,
//  URLOPT_SSL_VERIFYHOST,
//  URLOPT_SSL_VERIFYPEER,
//  URLOPT_RETURNTRANSFER,
//  URLOPT_FOLLOWLOCATION,
//  CURLOPT_URL,         // QUrlQuery
//  CURLOPT_HTTPHEADER,  // QStringList
//  CURLOPT_COOKIEJAR,   // QString
//  CURLOPT_USERAGENT,
//  CURLOPT_REFERER,
//};

enum RequestResult {
  FAILURE = 0,
  SUCCESS,
};

struct RequestPackage {
  QString url;
  QString login;
  QString password;
};
}  // namespace TestNetwork
QT_END_NAMESPACE

class TestNetworkManager : public QObject {
  Q_OBJECT

 public:
  TestNetworkManager(QObject *parent = 0);
  ~TestNetworkManager();

 public:
  TestNetwork::RequestResult send(const TestNetwork::RequestPackage &package);

 private:
  QPointer<CookiesHandler> _cookiesHandler;
  QPointer<QtCurlManager> _curlManager;
};

class QtCurlManager : public QObject {
  Q_OBJECT

 public:
  QtCurlManager(QObject *parent = 0);

 public:
  TestNetwork::RequestResult sendRequest();
  void setPackage(const TestNetwork::RequestPackage &package);

 private:
  TestNetwork::RequestResult sendPostRequest();
  TestNetwork::RequestResult sendGetRequest();

 private:
  QtCUrl _curl;
  TestNetwork::RequestPackage _package;
  const QString _userAgent =
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) "
      "Chrome/35.0.2309.372 Safari/537.36";
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
  QPointer<QNetworkAccessManager> _networkManager;
};

#endif  // TESTNETWORKMANAGER_H
