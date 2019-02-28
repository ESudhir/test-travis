#ifndef PAYMENTDIALOG_H
#define PAYMENTDIALOG_H

#include <QDialog>

namespace Ui {
class PaymentDialog;
}

class PaymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentDialog(QWidget *parent = nullptr);
    ~PaymentDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void myfunction();
//public slots:
    //void myfunction();
private:
    Ui::PaymentDialog *ui;
    QTimer *timer;
};

#endif // FIFTHDIALOG_H
