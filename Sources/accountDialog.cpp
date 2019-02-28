#include "../Headers/accountDialog.h"
#include "ui_accountDialog.h"
#include <QMessageBox>
#include "../Headers/journeyDetDialog.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include "../Headers/loginDialog.h"
using namespace std;
extern int network_socket;
AccountDialog::AccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountDialog) {
    ui->setupUi(this);
}

AccountDialog::~AccountDialog() {
    delete ui;
}

void AccountDialog::on_pushButton_clicked() {                  // Function when sign-up button is clicked
    QString name = ui->lineEdit->text();
    QString username = ui->lineEdit_6->text();
    QString password = ui->lineEdit_4->text();           // Storing the details of the user
    QString contact = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();
    QString cpassword = ui->lineEdit_5->text();
    username += '\n';
    password += '\n';
    contact += '\n';
    email += '\n';
    name += '\n';
    cpassword += '\n';
    QByteArray ba1 = username.toLocal8Bit();
    QByteArray ba2 = password.toLocal8Bit();
    QByteArray ba3 = cpassword.toLocal8Bit();
    QByteArray ba4 = contact.toLocal8Bit();
    QByteArray ba5 = email.toLocal8Bit();
    QByteArray ba6 = name.toLocal8Bit();
    const char *c_str1 = ba1.data();
    const char *c_str2 = ba2.data();
    const char *c_str3 = ba3.data();
    const char *c_str4 = ba4.data();                     // Converting the details to char data-type
    const char *c_str5 = ba5.data();
    const char *c_str6 = ba6.data();
    if ((c_str1[0] == '\n') || (c_str2[0] == '\n') || (c_str3[0] == '\n') || (c_str4[0] == '\n') || (c_str5[0] == '\n') || (c_str6[0] == '\n')) {  // If anyone of these details is blank we get the following pop-up window
        QMessageBox::warning(this, "Account creation", "All fields are mandatory");
    } else if (strlen(c_str2) < 8) {                                                                                                         // Length of the password must be greater than 7
        QMessageBox::warning(this, "Account creation", "Password must contain atleast 8 characters");
    } else if (password != cpassword) {                                                                                                      // To check whether the password entered while confirmig are same
        QMessageBox::warning(this, "Account creation", "Passwords donot match");
    } else {
        send(network_socket, c_str1, 100, 0);      // Sending signup details to server
        send(network_socket, c_str4, 12, 0);
        send(network_socket, c_str5, 100, 0);
        send(network_socket, c_str2, 100, 0);                                                                                               // Sending the details of the user to the database
        send(network_socket , c_str6, 300, 0);
        char confirm[4];
        recv(network_socket, &confirm, 4, 0);                                                                                               // Receives 0 if the username already exists else 1
        if (confirm[0] == '1') {                                                                                                            // If received is 1 then we execute the third dialog
            QMessageBox::about(this, "Success", "Your acount has been created succesfully");
            hide();
            JourneyDetDialog journeyDetDialog;
            journeyDetDialog.setModal(true);
            journeyDetDialog.exec();
         } else {                                                                                                                          // If received is 0 then we get warning to change the username
            QMessageBox::warning(this, "Account creation", "Username already taken");
        }
    }
}

void AccountDialog::on_pushButton_2_clicked() {               // Function when Back button is clicked
    send(network_socket, "#\n", 100, 0);
    send(network_socket, "#\n", 12, 0);
    send(network_socket, "#\n", 100, 0);                   // Sending '#' to server to ensure that server knows Back button is clicked
    send(network_socket, "#\n", 100, 0);
    send(network_socket, "#\n", 300, 0);
    hide();
    LoginDialog *mainWindow = new LoginDialog();          // Main Window is executed after we click the back button
        mainWindow->show();
}
