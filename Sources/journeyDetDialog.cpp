#include "../Headers/journeyDetDialog.h"
#include "ui_journeyDetDialog.h"
#include "../Headers/seatsDialog.h"
#include "../Headers/loginDialog.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <QMessageBox>
#include <QDateEdit>
#include "../Headers/date.h"
using namespace std;
extern int network_socket;
JourneyDetDialog::JourneyDetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JourneyDetDialog) {
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

JourneyDetDialog::~JourneyDetDialog() {
    delete ui;
}

void JourneyDetDialog::on_pushButton_clicked() {                                  // Function when search button is clicked
    QString from = ui->comboBox_from->currentText();                       // Taking the details from the user
    QString to = ui->comboBox_to->currentText();
    QDate myDate = ui->dateEdit->date();                                    // This is only vlaid if u visually design the window and placed dateEdit
    QString dateString = myDate.toString();
    QByteArray ba1 = from.toLocal8Bit();
    QByteArray ba2 = to.toLocal8Bit();
    QByteArray ba3 = dateString.toLocal8Bit();
    const char *c_str1 = ba1.data();                                       // Converting the details to char data-type
    const char *c_str2 = ba2.data();
    const char *c_str3 = ba3.data();
    if (!strcmp(c_str1, c_str2)) {                                           // If the origin and destination is same then we get warning to select different places
        QMessageBox::warning(this, "Alert", "Please choose a destination that is different from your origin");
    } else {
        send(network_socket, c_str1, 50, 0);
        send(network_socket, c_str2, 50, 0);                                  // Sending the origin,destination,date to the server
        send(network_socket, c_str3, 20, 0);
        hide();
        SeatsDialog seatsDialog;
        seatsDialog.setModal(true);                                       // Fourth dialog is executed
        seatsDialog.exec();
    }
}

void JourneyDetDialog::on_pushButton_2_clicked() {                                // Function when logout button is clicked
    send(network_socket, "#\n", 50, 0);
    send(network_socket, "#\n", 50, 0);                                       // Sending '#' to server to ensure that server knows Back button is clicked
    send(network_socket, "#\n", 20, 0);
    hide();
    LoginDialog *mainWindow = new LoginDialog();                             // Main Window is executed
        mainWindow->show();
}

void JourneyDetDialog::on_toolButton_clicked() {                                  // Function when tool button is clicked to select the date
    ui->dateEdit->setReadOnly(true);
    date dates;
    int result = dates.exec();
    if (result == QDialog::Accepted) {
        QString day;
        QDate date = dates.selectedDate();
        QDate today = QDate::currentDate();
        if ((today.month() == (date.month()-1)&&today.day() <= date.day())&&(today.year() == date.year())) {                                              // Next month
            QMessageBox::about(this, "Select correct Date", "Booking is only available upto same date in the next month");
            ui->pushButton->setEnabled(false);
        } else if (date.month() > today.month()+1&&(today.year() == date.year())) {                                                                      // After 1 month
            QMessageBox::about(this, "Select correct Date", "Booking is only available upto same date in the next month");
            ui->pushButton->setEnabled(false);
        } else if (today.month() == date.month()&&today.day() > date.day()&&(today.year() == date.year())) {                                              // Same year ,same month
            QMessageBox::about(this, "Select correct Date", "Booking is only available upto same date in the next month");
            ui->pushButton->setEnabled(false);
        } else if (today.month() > date.month()) {
            QMessageBox::about(this, "Select correct Date", "Booking is only available upto same date in the next month");
        } else if (today.year() != date.year()&&(today.month() != 12 || date.month() != 1)) {                                                              // Booking in dec
            QMessageBox::about(this, "Select correct Date", "Booking is only available upto same date in the next month");
            ui->pushButton->setEnabled(false);
        } else {
            ui->dateEdit->setDate(date);
            ui->pushButton->setEnabled(true);
        }
}
}
