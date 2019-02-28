#include "../Headers/seatsDialog.h"
#include "ui_seatsDialog.h"
#include "../Headers/journeyDetDialog.h"
#include "../Headers/paymentDialog.h"
#include "../Headers/loginDialog.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <QMessageBox>
using namespace std;
extern int network_socket;
int No_Of_Seats_Selected;                                                // Variable for Number of seats selected
char a[50], b[50];
SeatsDialog::SeatsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeatsDialog) {
    ui->setupUi(this);
    ui->pushButton_49->setEnabled(false);
    recv(network_socket, &a, 50, 0);        // Recieves seats from server
    No_Of_Seats_Selected = 0;
    if (a[0] == '1') {
        ui->pushButton->setEnabled(false);
    }
    for (int i = 1 ; i < 48 ; i++) {        // Loop for disabling already selected seats
        if (a[i] == '1') {
            QString seat = QString::number(i+1);
            QString s = "pushButton_"+seat;
            findChild<QPushButton *>(s)->setEnabled(false);
        }
    }

    strcpy(b, a);
}

SeatsDialog::~SeatsDialog() {
    delete ui;
}

void SeatsDialog::on_pushButton_clicked() {                                   // Function when SEAT 'A1' is selected
    if (a[0] == '0') {                                                          // if  it is not selected
        ui->pushButton->setStyleSheet("background-color: red");              // Mark it red to know it is selected
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;                                              // Increasing the number of seats selected
        a[0]  =  '1';                                                            // Setting it as selected
     } else {                                                                   // if  it is already selected and we are deselecting
        ui->pushButton->setStyleSheet("background-color: white");            // Mark it white to know it is deselected
        No_Of_Seats_Selected--;                                              // Decreasing the number of seats selected
        if (!No_Of_Seats_Selected)                                            // if  number of seats selected is 0 then disabling confirm_booking button
            ui->pushButton_49->setEnabled(false);
        a[0]  =  '0';                                                            // Setting it as not selected
    }
}
void SeatsDialog::on_pushButton_2_clicked() {
    if (a[1] == '0')  {
        ui->pushButton_2->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[1] = '1';
     } else  {
        ui->pushButton_2->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[1] = '0';
    }
}
void SeatsDialog::on_pushButton_3_clicked() {
    if (a[2] == '0')  {
        ui->pushButton_3->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[2] = '1';
     } else {
        ui->pushButton_3->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[2] = '0';
    }
}
void SeatsDialog::on_pushButton_4_clicked() {
    if (a[3] == '0') {
        ui->pushButton_4->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[3] = '1';
     } else {
        ui->pushButton_4->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[3] = '0';
    }
}
void SeatsDialog::on_pushButton_5_clicked() {
    if (a[4] == '0') {
        ui->pushButton_5->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[4] = '1';
     } else {
        ui->pushButton_5->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[4] = '0';
    }
}
void SeatsDialog::on_pushButton_6_clicked() {
    if (a[5] == '0') {
        ui->pushButton_6->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[5] = '1';
     } else {
        ui->pushButton_6->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[5] = '0';
    }
}
void SeatsDialog::on_pushButton_7_clicked() {
    if (a[6] == '0') {
        ui->pushButton_7->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[6] = '1';
     } else {
        ui->pushButton_7->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[6] = '0';
    }
}

void SeatsDialog::on_pushButton_8_clicked() {
    if (a[7] == '0') {
        ui->pushButton_8->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[7] = '1';
     } else {
        ui->pushButton_8->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[7] = '0';
    }
}

void SeatsDialog::on_pushButton_9_clicked() {
    if (a[8] == '0') {
        ui->pushButton_9->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[8] = '1';
     } else {
        ui->pushButton_9->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[8] = '0';
    }
}
void SeatsDialog::on_pushButton_10_clicked() {
    if (a[9] == '0') {
        ui->pushButton_10->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[9] = '1';
     } else {
        ui->pushButton_10->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[9] = '0';
    }
}

void SeatsDialog::on_pushButton_11_clicked() {
    if (a[10] == '0') {
        ui->pushButton_11->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[10] = '1';
     } else {
        ui->pushButton_11->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[10] = '0';
    }
}

void SeatsDialog::on_pushButton_12_clicked() {
    if (a[11] == '0') {
        ui->pushButton_12->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[11] = '1';
     } else {
        ui->pushButton_12->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[11] = '0';
    }
}

void SeatsDialog::on_pushButton_13_clicked() {
    if (a[12] == '0') {
        ui->pushButton_13->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[12] = '1';
     } else {
        ui->pushButton_13->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[12] = '0';
    }
}


void SeatsDialog::on_pushButton_14_clicked() {
    if (a[13] == '0') {
        ui->pushButton_14->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[13] = '1';
     } else {
        ui->pushButton_14->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[13] = '0';
    }
}

void SeatsDialog::on_pushButton_15_clicked() {
    if (a[14] == '0') {
        ui->pushButton_15->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[14] = '1';
     } else {
        ui->pushButton_15->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[14] = '0';
    }
}


void SeatsDialog::on_pushButton_16_clicked() {
    if (a[15] == '0') {
        ui->pushButton_16->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[15] = '1';
     } else {
        ui->pushButton_16->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[15] = '0';
    }
}

void SeatsDialog::on_pushButton_17_clicked() {
    if (a[16] == '0') {
        ui->pushButton_17->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[16] = '1';
     } else {
        ui->pushButton_17->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[16] = '0';
    }
}

void SeatsDialog::on_pushButton_18_clicked() {
    if (a[17] == '0') {
        ui->pushButton_18->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[17] = '1';
     } else {
        ui->pushButton_18->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[17] = '0';
    }
}


void SeatsDialog::on_pushButton_19_clicked() {
    if (a[18] == '0') {
        ui->pushButton_19->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[18] = '1';
     } else {
        ui->pushButton_19->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[18] = '0';
    }
}



void SeatsDialog::on_pushButton_20_clicked() {
    if (a[19] == '0') {
        ui->pushButton_20->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[19] = '1';
     } else {
        ui->pushButton_20->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[19] = '0';
    }
}

void SeatsDialog::on_pushButton_21_clicked() {
    if (a[20] == '0') {
        ui->pushButton_21->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[20] = '1';
     } else {
        ui->pushButton_21->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[20] = '0';
    }
}

void SeatsDialog::on_pushButton_22_clicked() {
    if (a[21] == '0') {
        ui->pushButton_22->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[21] = '1';
     } else {
        ui->pushButton_22->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[21] = '0';
    }
}

void SeatsDialog::on_pushButton_23_clicked() {
    if (a[22] == '0') {
        ui->pushButton_23->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[22] = '1';
     } else {
        ui->pushButton_23->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[22] = '0';
    }
}

void SeatsDialog::on_pushButton_24_clicked() {
    if (a[23] == '0') {
        ui->pushButton_24->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[23] = '1';
     } else {
        ui->pushButton_24->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[23] = '0';
    }
}

void SeatsDialog::on_pushButton_25_clicked() {
    if (a[24] == '0') {
        ui->pushButton_25->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[24] = '1';
     } else {
        ui->pushButton_25->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[24] = '0';
    }
}

void SeatsDialog::on_pushButton_26_clicked() {
    if (a[25] == '0') {
        ui->pushButton_26->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[25] = '1';
     } else {
        ui->pushButton_26->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[25] = '0';
    }
}

void SeatsDialog::on_pushButton_27_clicked() {
    if (a[26] == '0') {
        ui->pushButton_27->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[26] = '1';
     } else {
        ui->pushButton_27->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[26] = '0';
    }
}

void SeatsDialog::on_pushButton_28_clicked() {
    if (a[27] == '0') {
        ui->pushButton_28->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[27] = '1';
     } else {
        ui->pushButton_28->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[27] = '0';
    }
}

void SeatsDialog::on_pushButton_29_clicked() {
    if (a[28] == '0') {
        ui->pushButton_29->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[28] = '1';
     } else {
        ui->pushButton_29->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[28] = '0';
    }
}

void SeatsDialog::on_pushButton_30_clicked() {
    if (a[29] == '0') {
        ui->pushButton_30->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[29] = '1';
     } else {
        ui->pushButton_30->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[29] = '0';
    }
}

void SeatsDialog::on_pushButton_31_clicked() {
    if (a[30] == '0') {
        ui->pushButton_31->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[30] = '1';
     } else {
        ui->pushButton_31->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[30] = '0';
    }
}

void SeatsDialog::on_pushButton_32_clicked() {
    if (a[31] == '0') {
        ui->pushButton_32->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[31] = '1';
     } else {
        ui->pushButton_32->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[31] = '0';
    }
}



void SeatsDialog::on_pushButton_33_clicked() {
    if (a[32] == '0') {
        ui->pushButton_33->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[32] = '1';
     } else {
        ui->pushButton_33->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[32] = '0';
    }
}



void SeatsDialog::on_pushButton_34_clicked() {
    if (a[33] == '0') {
        ui->pushButton_34->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[33] = '1';
     } else {
        ui->pushButton_34->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[33] = '0';
    }
}

void SeatsDialog::on_pushButton_35_clicked() {
    if (a[34] == '0') {
        ui->pushButton_35->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[34] = '1';
     } else {
        ui->pushButton_35->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[34] = '0';
    }
}



void SeatsDialog::on_pushButton_36_clicked() {
    if (a[35] == '0') {
        ui->pushButton_36->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[35] = '1';
     } else {
        ui->pushButton_36->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[35] = '0';
    }
}




void SeatsDialog::on_pushButton_37_clicked() {
    if (a[36] == '0') {
        ui->pushButton_37->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[36] = '1';
     } else {
        ui->pushButton_37->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[36] = '0';
    }
}




void SeatsDialog::on_pushButton_38_clicked() {
    if (a[37] == '0') {
        ui->pushButton_38->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[37] = '1';
     } else {
        ui->pushButton_38->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[37] = '0';
    }
}



void SeatsDialog::on_pushButton_39_clicked() {
    if (a[38] == '0') {
        ui->pushButton_39->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[38] = '1';
     } else {
        ui->pushButton_39->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[38] = '0';
    }
}



void SeatsDialog::on_pushButton_40_clicked() {
    if (a[39] == '0') {
        ui->pushButton_40->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[39] = '1';
     } else {
        ui->pushButton_40->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[39] = '0';
    }
}


void SeatsDialog::on_pushButton_41_clicked() {
    if (a[40] == '0') {
        ui->pushButton_41->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[40] = '1';
     } else {
        ui->pushButton_41->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[40] = '0';
    }
}



void SeatsDialog::on_pushButton_42_clicked() {
    if (a[41]  ==  '0') {
        ui->pushButton_42->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[41] = '1';
     } else {
        ui->pushButton_42->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if  (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[41] = '0';
    }
}



void SeatsDialog::on_pushButton_43_clicked() {
    if (a[42] == '0') {
        ui->pushButton_43->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[42] = '1';
     } else  {
        ui->pushButton_43->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[42] = '0';
    }
}




void SeatsDialog::on_pushButton_44_clicked() {
    if (a[43] == '0') {
        ui->pushButton_44->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[43] = '1';
     } else {
        ui->pushButton_44->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[43] = '0';
    }
}



void SeatsDialog::on_pushButton_45_clicked() {
    if (a[44] == '0') {
        ui->pushButton_45->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[44] = '1';
     } else {
        ui->pushButton_45->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[44] = '0';
    }
}



void SeatsDialog::on_pushButton_46_clicked() {
    if (a[45] == '0') {
        ui->pushButton_46->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[45] = '1';
     } else {
        ui->pushButton_46->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[45] = '0';
    }
}

void SeatsDialog::on_pushButton_47_clicked() {
    if (a[46] == '0') {
        ui->pushButton_47->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[46] = '1';
     } else {
        ui->pushButton_47->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[46] = '0';
    }
}
void SeatsDialog::on_pushButton_48_clicked() {
    if (a[47] == '0')  {
        ui->pushButton_48->setStyleSheet("background-color: red");
        ui->pushButton_49->setEnabled(true);
        No_Of_Seats_Selected++;
        a[47] = '1';
    } else {
        ui->pushButton_48->setStyleSheet("background-color: white");
        No_Of_Seats_Selected--;
        if (!No_Of_Seats_Selected)
            ui->pushButton_49->setEnabled(false);
        a[47] = '0';
    }
}
void SeatsDialog::on_pushButton_49_clicked() {                                    // Function when confirm_booking button is clicked
    char c[50];
    int s = 0;
    for (int i = 0 ; i < 48 ; i++) {
        if (a[i] != b[i]) {     // Checking what all seats are booked
            c[s] = i+48;        // Storing indices of booked seats
            s++;
         }
    }
    c[s] = '\n';
    send(network_socket, &c, 50, 0);    // Sending selected seats to server
    char aq[4];
    recv(network_socket, &aq, 4, 0);
    if (aq[0] == 'w') {                 // 'w' is the keyword for payment process
        hide();
        PaymentDialog paymentDialog;        // Opening payment dialog
        paymentDialog.setModal(true);
        paymentDialog.exec();
     } else {                           // One or more of selected seats are unavailable
        hide();
        QMessageBox::warning(this, "Failed", "Seats not available");
        SeatsDialog seatsDialog;
        seatsDialog.setModal(true);
        seatsDialog.exec();
    }
}

void SeatsDialog::on_pushButton_50_clicked() {                                     // Function when LOGOUT button is clicked
    send(network_socket, "#\n", 50, 0);                                                // Sending '#' to server to ensure that server knows LOGOUT button is clicked
    hide();
    LoginDialog *mainWindow  =  new LoginDialog();                                    // Main Window is executed
    mainWindow->show();
}

void SeatsDialog::on_pushButton_51_clicked() {                                     // Function when back button is clicked
    send(network_socket, "z\n", 50, 0);                                              // Sending '#' to server to ensure that server knows back button is clicked
    hide();
    JourneyDetDialog journeyDetDialog;
    journeyDetDialog.setModal(true);                                                   // third dialog is executed
    journeyDetDialog.exec();
}
