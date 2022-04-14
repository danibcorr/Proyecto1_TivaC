#ifndef MAINUSERGUI_H
#define MAINUSERGUI_H

#include <QWidget>
#include <QtSerialPort/qserialport.h>
#include <QMessageBox>
#include "tiva_remotelink.h"

namespace Ui {
class MainUserGUI;
}

class MainUserGUI : public QWidget
{
    Q_OBJECT
    
public: 
    explicit MainUserGUI(QWidget *parent = 0);
    ~MainUserGUI();
    
private slots:
    // slots privados asociados mediante "connect" en el constructor
    void cambiaLEDs();
    void tivaStatusChanged(int status,QString message);
    void messageReceived(uint8_t type, QByteArray datos);
    void cambiaMODO();
    void colorWheel_cambiaRGB(const QColor &arg1);
    void cambiaBrillo(double value);
    void comprobarEstado();
    void comprobarEstado_Eventos();

    //Slots asociados por nombre
    void on_runButton_clicked();    
    void on_serialPortComboBox_currentIndexChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_ADCButton_clicked();
    void on_pingButton_clicked();

private:
    // funciones privadas
    void processError(const QString &s);
    void activateRunButton();

private:
    //Componentes privados
    Ui::MainUserGUI *ui;
    int transactionCount;
    QMessageBox ventanaPopUp;
    TivaRemoteLink tiva; //Objeto para gestionar la comunicacion de mensajes con el microcontrolador

};

#endif // GUIPANEL_H
