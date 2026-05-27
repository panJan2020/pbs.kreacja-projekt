#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>      // combo bibliotek do tekstów
#include <QApplication> // sterowanie aplikacją
#include <QMessageBox>  // proste okienka iterakcji

#include <QLabel>       // etykieta tekst infomacyjny - Read Only
#include <QProgressBar> // pasek postepu
#include <QTime>        // obsługa czasu
#include <QTimer>       // obsługa procesu timerOS
#include <QPoint>       // obsługa punktu ekranu

#include "dialog.h"     // nasza własna klasa okienta O Programie
#include "mylabelfilter.h"

#include <QImage>       // biblioteka pbsługi formatów graficznych
#include <QPixmap>      // biblioteka bufora pamięci pikseli
#include <QFileDialog>  // biblioteka współpracy z systemem plików

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setInfo(QString tekst, int ile); // metoda do wyświetlenia komunikatu w polu statusowym na określony czas

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

public slots:
    void on_timeout();          // nasz własny slot obsługi tyknięć zegarka w aplikacji

private slots:
    void on_action_Koniec_triggered();

    void on_actionO_Prog_ramie_triggered();

    void on_action_Otw_rz_triggered();

    void on_actionZapi_sz_triggered();

    // PODPUNKT E: Nowy slot do obsługi odebranego sygnału kliknięcia
    void mamKlikniecieMyszki(int x, int y);

private:
    Ui::MainWindow *ui;
    MyLabelFilter *filtrLabela;

    QLabel info,czas_info;      // teksty wyświetlane w pasku statusowym
    QProgressBar pasek;         // pasek postępu wyświetlany w pasku statusowym
    QTime czas;                 // zmienna do obsługi czasu dla potrzeb aplikacji
    QTimer *zegarek;
    int licznik;                // zmienna licznika kontrolowania czasu wyświetlania informacji w pasku statusowym
    Dialog oknoAbout;           // nasze okienko O Programie...

    QImage *plik_obrazka;       // nasz plik graficzny do odczytu
    QPixmap piksele_obrazu;     // nasz bufor pikseli obrazu
    QString nazwa_pliku;        // zmienna do nazwy wybranego pliku graficznego



    bool mam_shift;             // zmienne określająca czy klawisz shift jest wciśnięty, czy też nie

};
#endif // MAINWINDOW_H
