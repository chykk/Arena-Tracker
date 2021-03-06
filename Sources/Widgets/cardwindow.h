#ifndef CARDWINDOW_H
#define CARDWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QLabel>

#define HCARD 254
#define WCARD 182

class CardWindow : public QMainWindow
{
    Q_OBJECT

//Constructor
public:
    CardWindow(QWidget *parent);
    ~CardWindow();

//Variables
private:
    QLabel *cardLabel;
    bool alwaysHidden;

//Metodos
public:


signals:

public slots:
    void loadCard(QString code, QRect rectCard, int maxTop, int maxBottom, bool alignReverse=false);
    void scale(int value_x10);
};

#endif // CARDWINDOW_H
