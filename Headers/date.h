#ifndef DATE_H
#define DATE_H

#include <QDialog>
#include <QDate>
class QCalendarWidget;
class QDialogButtonBox;
class QVBoxLayout;

class date : public QDialog{
    Q_OBJECT

public:
    date(QWidget *parent=0);
    QDate selectedDate() const;

private:
    QWidget *widget;
    QCalendarWidget *calendarWidget;
    QDialogButtonBox* buttonBox;
    QVBoxLayout *verticalLayout;
};

#endif // DATE_H
