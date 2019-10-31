#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
#include <QApplication>
#include <QFile>
#include <QTextStream>

#include <math.h>
#include <sstream>
#include <vector>
#include <complex>
#include <fftw3.h>

#include "qcustomplot.h"



using namespace std;
typedef complex<double> complexf;

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QStandardPaths>
#include <QStandardItem>
#include <QTableView>
#include <QFlags>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void load_data_fin();
    void fft_end();
    void pz_getmodl_fin();
    void pz_getpz_fin();

public slots:
    void plot_timeres();
    void plot_timeres_autoscale();
    void plot_timeres_setrange();
    void plot_fft();
    void plot_fft_autoscale();
    void plot_fft_setrange();
    void plot_si();
    void stat_start();
    void fft_start();
    void pz_lsm_start();
    void pz_get_pz();
    void set_timetable();
    void save_data();
    void open_data();
    void load_data();

private:
    Ui::MainWindow *ui;

    //Validator
    QIntValidator *IntValidator;
    QIntValidator *NaturalValidator;
    QDoubleValidator *DoubleValidator;
    QDoubleValidator *DoublePosValidator;


    //Graph
    const int GRAPH_MAX_NUM=8;
    QVector <QColor> LineColor={
        QColor(0xc8,0x00,0x00),
        QColor(0x00,0x00,0xc8),
        QColor(0xc8,0x00,0x00),
        QColor(0xff,0xff,0x00),
        QColor(0x00,0xff,0xff),
        QColor(0xff,0x00,0xff),
    };

    //Table
    int DataT_Table_RowNUM = 0;
    int DataT_Table_ColNUM = 0;
    int ColumnCnt = 0;
    int DataT_RowNUM = 0;
    int DataT_ColNUM = 0;
    const int DataT_ROW_INIT=50;
    const int DataT_COL_INIT=10;
    const int DataT_ROW_MAX=2000;
    const int DataT_COL_MAX=8;
    const int TABLE_DIGIT=4;
    const char TABLE_FORMAT = 'e';

    //Data set: Time series
    double **Data;
    const int TS_DIGIT=4;
    const char TS_FORMAT= 'e';
    const int GET_TS_CNTWIDTH=10;

    //Statistics
    double SI_TS=0.0;

    //FFT
    const int FFT_MAX_NUM=12;
    int FFT_PlotNum=0;
    int FFT_ON=0;
    int FFT_DATA_NUM=0;
    double FFT_TS;
    double **FFT_Power;

    //PZ
    const int PZ_DIGIT=2;
    const char PZ_FORMAT = 'f';
    const double PZ_TRUNCATE = 1e-3;
    const double PZ_WN_MIN=1.0e-3;
    const double PZ_WN_WIDTH_MIN=5.0;
    const int DKA_ITERATION_NUM=3000;
    const int BODE_ITERATION=100000;
    const int APPROX_ORDER=6;
    int NUM_POLES=0;
    int NUM_ZEROS=0;
    int XData_INDICATOR=0;
    int UData_INDICATOR=0;
    double PZ_TS=0.0;
    double GZ_GAIN=0.0;
    double *Theta;

};

#endif // MAINWINDOW_H
