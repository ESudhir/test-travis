#ifndef JOURNEYDETDIALOG_H
#define JOURNEYDETDIALOG_H

#include <QDialog>

namespace Ui {
class JourneyDetDialog;
}

class JourneyDetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit JourneyDetDialog(QWidget *parent = nullptr);
    ~JourneyDetDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_clicked();

private:
    Ui::JourneyDetDialog *ui;
};

#endif // THIRDDIALOG_H
