#include "../Headers/paymentDialog.h"
#include "../Headers/seatsDialog.h"
#include "ui_paymentDialog.h"
#include "../Headers/loginDialog.h"
#include <QMessageBox>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <QTimer>
#include <QDateTime>
using namespace std;
extern int network_socket;
extern int No_Of_Seats_Selected;
int check, t;
PaymentDialog::PaymentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentDialog) {
    ui->setupUi(this);
    t = 10;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer->start(1000);
    ui->label_7->setText("100 Rs.");
    ui->label_8->setText(QString::number(No_Of_Seats_Selected) + "   ");
    ui->label_9->setText(QString::number(100*No_Of_Seats_Selected) + " Rs.");
    ui->label_10->setText(QString::number(10*No_Of_Seats_Selected) + " Rs.");
    ui->label_11->setText(QString::number(110*No_Of_Seats_Selected) + " Rs.");
    check = 0;
    ui->pushButton->setEnabled(false);
}

PaymentDialog::~PaymentDialog() {
    delete ui;
}

void PaymentDialog::on_pushButton_2_clicked() {       // Back pushbutton is clicked
    hide();
    timer->QTimer::stop();
    send(network_socket, "y\n", 4, 0);              // Keyword for back button so that server knows
    SeatsDialog fourthdialog;
    fourthdialog.setModal(true);
    fourthdialog.exec();
}

void PaymentDialog::on_pushButton_clicked() {
    timer->QTimer::stop();                      // Stop the timer interrupt
    send(network_socket, "x\n", 4, 0);          // Payment is done in time, x is the keyword for successful payment
    QMessageBox::about(this, "Success", "Your tickets are booked successfully");     // Displays successfully booked message
    hide();
    SeatsDialog fourthdialog;
    fourthdialog.setModal(true);
    fourthdialog.exec();
}

void PaymentDialog::on_checkBox_stateChanged(int arg1) {      // Checkbox corresponding to terms and conditions
    if (check == 0) {                                       // Checkbox is ticked
        check = 1;
        ui->pushButton->setEnabled(true);                   // User can book seats as he agreed to terms and conditions
    } else {
        check = 0;
        ui->pushButton->setEnabled(false);                  // User cannot book seats as he didn't agreed to terms and conditions
    }
}
void PaymentDialog::myfunction() {
    ui->label_time->setText(QVariant(t).toString());      // label_time is label which displays timer
    if (t == 0) {                                         // t=0 means time is up
        timer->QTimer::stop();                            // Stop the timer interrupt
        send(network_socket, "y\n", 4, 0);                // 'y' is keyword for timeout. Server cancels seats upon recieving 'y'
        QMessageBox::warning(this, "Time out", "Session expired");  // Displays timeout message
        hide();
        SeatsDialog fourthdialog;
        fourthdialog.setModal(true);
        fourthdialog.exec();
    }
    t--;                                                    // Decrementing time
}
