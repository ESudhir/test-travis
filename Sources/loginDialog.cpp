#include "../Headers/loginDialog.h"
#include "ui_loginDialog.h"
#include <QMessageBox>
#include "../Headers/accountDialog.h"
#include "../Headers/journeyDetDialog.h"
#include <QPixmap>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
using namespace std;
extern int network_socket;
LoginDialog::LoginDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginDialog) {
    ui->setupUi(this);
    QPixmap pics(":/Images/Imgs/train_mainWindow.jpeg");                  // Copying the path of the image in the resource folder
    ui->label_5->setPixmap(pics.scaled(350, 350, Qt::KeepAspectRatio));     // Setting the Aspect Ratio of the image
    this->setStyleSheet("background-color: white;");
}

LoginDialog::~LoginDialog() {
    delete ui;
}

void LoginDialog::on_pushButton_clicked() {                // Function when sign-in button is clicked
    QString username = ui->lineEdit_username->text();    // Taking the username and password
    QString password = ui->lineEdit_password->text();
    username+='\n';
    password+='\n';
    QByteArray ba1 = username.toLocal8Bit();
    QByteArray ba2 = password.toLocal8Bit();
    const char *c_str1 = ba1.data();
    const char *c_str2 = ba2.data();                     // Converting the details to char data-type
    send(network_socket, c_str1, 100, 0);
    send(network_socket, c_str2, 100, 0);                   // Sending the username and password to the database
    char confirm[4];
    recv(network_socket, &confirm, 4, 0);                   // Receives 1 if the account already exists else 0
    if (confirm[0] == '1') {                             // If received is 1 then we execute the third dialog
        hide();
        JourneyDetDialog journeyDetDialog;
        journeyDetDialog.setModal(true);
        journeyDetDialog.exec();
    } else {                                                 // If received is 0 then the account details we have entered are incorrect
        QMessageBox::warning(this, "Log In", "Incorrect username or password");
    }
}

void LoginDialog::on_pushButton_2_clicked() {               // Function when sign-up button is clicked
    send(network_socket, "#\n", 100, 0);                    // Sending '#' to server to ensure that server knows sign-up button is clicked
    send(network_socket, "#\n", 100, 0);
    hide();
    AccountDialog accountDialog;
    accountDialog.setModal(true);                            // Executing the second dialog
    accountDialog.exec();
}
