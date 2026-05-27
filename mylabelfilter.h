#ifndef MYLABELFILTER_H
#define MYLABELFILTER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>

class MyLabelFilter : public QObject
{
    Q_OBJECT
public:
    explicit MyLabelFilter(QObject *parent = nullptr);

protected:
    // Nadpisujemy funkcję eventFilter, aby przechwytywać zdarzenia myszy
    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    // PODPUNKT D: Deklaracja własnego sygnału z dwoma parametrami (x, y)
    void klikniecieMyszki(int x, int y);

private:
    bool mam_lewyklawisz; // <-- Nowa zmienna przechowująca stan lewego klawisza

};

#endif // MYLABELFILTER_H