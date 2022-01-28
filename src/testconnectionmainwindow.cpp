#include "testconnectionmainwindow.h"

#include <QSizePolicy>
#include <QtWidgets>

#include "ui_testconnectionmainwindow.h"

QString ConnectionLink::parsed() {
  return _url;
}

TestConnectionMainWindow::TestConnectionMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TestConnectionMainWindow) {
  ui->setupUi(this);
  content = new TestConnectionMainWindowContent(ui);
  networkManager = new NetworkManager();
  setWindowGeometry(_w, _h);
  setConnections();
}

TestConnectionMainWindow::~TestConnectionMainWindow() { delete ui; }

void TestConnectionMainWindow::setWindowGeometry(int width, int height) {
  const QRect &r = QGuiApplication::primaryScreen()->availableGeometry();
  move(qAbs(r.width() - width) / 2, qAbs(r.height() - height) / 2);
  setFixedSize(_w, _h);
}

void TestConnectionMainWindow::setConnections() {}

void TestConnectionMainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    content->onButtonPressed();
  }
}

TestConnectionMainWindowContent::TestConnectionMainWindowContent(
    Ui::TestConnectionMainWindow *ui, QObject *parent)
    : QObject(parent) {
  this->ui = ui;
  this->ui->label->setText(_welcomeHeader + " " + _siteName.toString());
  setConnections();
}

void TestConnectionMainWindowContent::setConnections() {
  connect(ui->pushButton, &QPushButton::pressed, this,
          &TestConnectionMainWindowContent::onButtonPressed);
}

void TestConnectionMainWindowContent::onButtonPressed() {
  QString login = ui->lineEdit_login->text();
  QString password = ui->lineEdit_password->text();
}

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent), testNetworkManager(new TestNetworkManager) {}

NetworkManager::~NetworkManager() {}
