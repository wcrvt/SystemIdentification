/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_14;
    QWidget *widget_dataselect;
    QHBoxLayout *horizontalLayout;
    QLineEdit *data_path;
    QPushButton *data_load;
    QPushButton *data_select;
    QWidget *widget_input_splitter;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *input_separator_tab;
    QRadioButton *input_separator_comma;
    QRadioButton *input_separator_space;
    QWidget *widget_exit;
    QGridLayout *gridLayout_8;
    QPushButton *button_exit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QWidget *widget_table;
    QGridLayout *gridLayout_2;
    QTableWidget *table_data;
    QWidget *widget_tab;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_timeres;
    QGridLayout *gridLayout_11;
    QWidget *time_timerange;
    QGridLayout *gridLayout_10;
    QLineEdit *time_timerange_xmax;
    QPushButton *time_timerange_set;
    QLabel *time_timerange_label1;
    QLineEdit *time_timerange_ymin;
    QLabel *time_timerange_label2;
    QPushButton *time_timerange_auto;
    QLabel *label_14;
    QLabel *time_timerange_label3;
    QLineEdit *time_timerange_xmin;
    QLabel *time_timerange_label4;
    QLineEdit *time_timerange_ymax;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_stochastic;
    QGridLayout *gridLayout_5;
    QLabel *time_stat_label5;
    QLineEdit *time_stat_result_variance;
    QPushButton *time_stat_start;
    QLabel *time_stat_label3;
    QLineEdit *time_stat_time_et;
    QLabel *time_stat_label7;
    QLabel *time_stat_label1;
    QLineEdit *time_ts;
    QLabel *time_stat_label9;
    QLineEdit *time_stat_result_mean;
    QLineEdit *time_stat_column;
    QLineEdit *time_stat_result_skew;
    QLineEdit *time_stat_result_kurtosis;
    QLineEdit *time_stat_time_st;
    QLabel *time_stat_label8;
    QLabel *time_stat_label4;
    QLabel *time_stat_label2;
    QLabel *time_stat_label6;
    QWidget *tab_fft;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_setting;
    QGridLayout *gridLayout_6;
    QWidget *widget_timerange;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *fft_timerange_et;
    QLineEdit *fft_timerange_st;
    QLabel *label_16;
    QLabel *label_6;
    QLineEdit *fft_ts;
    QCheckBox *fft_timerange_ena;
    QLabel *label_5;
    QCheckBox *fft_logscaleY_on;
    QPushButton *fft_start;
    QWidget *widget_freqrange;
    QGridLayout *gridLayout_9;
    QLabel *fft_freqrange_label1;
    QLineEdit *fft_freqrange_ymin;
    QLineEdit *fft_freqrange_xmax;
    QPushButton *fft_freqrange_auto;
    QLabel *fft_freqrange_label4;
    QLabel *fft_freqrange_label2;
    QLabel *fft_freqrange_label3;
    QLineEdit *fft_freqrange_xmin;
    QLineEdit *fft_freqrange_ymax;
    QPushButton *fft_freqrange_set;
    QLabel *label_13;
    QSpacerItem *verticalSpacer;
    QWidget *tab_si;
    QGridLayout *gridLayout_7;
    QWidget *widget__si_start;
    QVBoxLayout *verticalLayout;
    QPushButton *si_start;
    QWidget *widget_si_setting;
    QGridLayout *gridLayout_12;
    QLineEdit *si_column_in;
    QLineEdit *si_num_Z;
    QLineEdit *si_num_P;
    QLineEdit *si_ts;
    QLineEdit *si_column_res;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *widget_si_result;
    QGridLayout *gridLayout_13;
    QLabel *si_result_label_5;
    QTextEdit *si_result_zero;
    QTextEdit *si_result_tfz;
    QLineEdit *si_result_dc;
    QLabel *si_result_label_3;
    QLabel *label_2;
    QTextEdit *si_result_pole;
    QTextEdit *si_result_tfs;
    QLabel *si_result_label_4;
    QLabel *si_result_label_12;
    QLabel *si_result_label_2;
    QLineEdit *si_result_wn;
    QWidget *widget_graph;
    QGridLayout *gridLayout_3;
    QCustomPlot *graph_fft;
    QCustomPlot *graph_si;
    QCustomPlot *graph_timeres;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1114, 915);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_14 = new QGridLayout(centralWidget);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        widget_dataselect = new QWidget(centralWidget);
        widget_dataselect->setObjectName(QString::fromUtf8("widget_dataselect"));
        widget_dataselect->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(widget_dataselect);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        data_path = new QLineEdit(widget_dataselect);
        data_path->setObjectName(QString::fromUtf8("data_path"));
        data_path->setMinimumSize(QSize(180, 0));

        horizontalLayout->addWidget(data_path);

        data_load = new QPushButton(widget_dataselect);
        data_load->setObjectName(QString::fromUtf8("data_load"));

        horizontalLayout->addWidget(data_load);

        data_select = new QPushButton(widget_dataselect);
        data_select->setObjectName(QString::fromUtf8("data_select"));

        horizontalLayout->addWidget(data_select);

        widget_input_splitter = new QWidget(widget_dataselect);
        widget_input_splitter->setObjectName(QString::fromUtf8("widget_input_splitter"));
        widget_input_splitter->setMinimumSize(QSize(0, 35));
        widget_input_splitter->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_2 = new QHBoxLayout(widget_input_splitter);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        input_separator_tab = new QRadioButton(widget_input_splitter);
        input_separator_tab->setObjectName(QString::fromUtf8("input_separator_tab"));

        horizontalLayout_2->addWidget(input_separator_tab);

        input_separator_comma = new QRadioButton(widget_input_splitter);
        input_separator_comma->setObjectName(QString::fromUtf8("input_separator_comma"));

        horizontalLayout_2->addWidget(input_separator_comma);

        input_separator_space = new QRadioButton(widget_input_splitter);
        input_separator_space->setObjectName(QString::fromUtf8("input_separator_space"));

        horizontalLayout_2->addWidget(input_separator_space);


        horizontalLayout->addWidget(widget_input_splitter);


        gridLayout_14->addWidget(widget_dataselect, 0, 0, 1, 1);

        widget_exit = new QWidget(centralWidget);
        widget_exit->setObjectName(QString::fromUtf8("widget_exit"));
        widget_exit->setMaximumSize(QSize(16777215, 50));
        gridLayout_8 = new QGridLayout(widget_exit);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        button_exit = new QPushButton(widget_exit);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));
        button_exit->setMinimumSize(QSize(100, 0));
        button_exit->setMaximumSize(QSize(100, 16777215));

        gridLayout_8->addWidget(button_exit, 0, 0, 1, 1);


        gridLayout_14->addWidget(widget_exit, 2, 0, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 700));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1088, 698));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_table = new QWidget(scrollAreaWidgetContents);
        widget_table->setObjectName(QString::fromUtf8("widget_table"));
        widget_table->setMinimumSize(QSize(340, 0));
        widget_table->setMaximumSize(QSize(340, 600));
        gridLayout_2 = new QGridLayout(widget_table);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        table_data = new QTableWidget(widget_table);
        if (table_data->columnCount() < 10)
            table_data->setColumnCount(10);
        if (table_data->rowCount() < 50)
            table_data->setRowCount(50);
        table_data->setObjectName(QString::fromUtf8("table_data"));
        table_data->setMaximumSize(QSize(1000, 600));
        table_data->setAutoScrollMargin(16);
        table_data->setRowCount(50);
        table_data->setColumnCount(10);
        table_data->horizontalHeader()->setMinimumSectionSize(30);
        table_data->horizontalHeader()->setDefaultSectionSize(80);
        table_data->verticalHeader()->setMinimumSectionSize(20);
        table_data->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_2->addWidget(table_data, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_table, 0, 0, 1, 1);

        widget_tab = new QWidget(scrollAreaWidgetContents);
        widget_tab->setObjectName(QString::fromUtf8("widget_tab"));
        widget_tab->setMinimumSize(QSize(400, 0));
        widget_tab->setMaximumSize(QSize(400, 600));
        verticalLayout_3 = new QVBoxLayout(widget_tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(widget_tab);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(1000, 600));
        tab_timeres = new QWidget();
        tab_timeres->setObjectName(QString::fromUtf8("tab_timeres"));
        gridLayout_11 = new QGridLayout(tab_timeres);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        time_timerange = new QWidget(tab_timeres);
        time_timerange->setObjectName(QString::fromUtf8("time_timerange"));
        time_timerange->setMaximumSize(QSize(1000, 125));
        gridLayout_10 = new QGridLayout(time_timerange);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        time_timerange_xmax = new QLineEdit(time_timerange);
        time_timerange_xmax->setObjectName(QString::fromUtf8("time_timerange_xmax"));

        gridLayout_10->addWidget(time_timerange_xmax, 1, 3, 1, 1);

        time_timerange_set = new QPushButton(time_timerange);
        time_timerange_set->setObjectName(QString::fromUtf8("time_timerange_set"));

        gridLayout_10->addWidget(time_timerange_set, 4, 3, 1, 1);

        time_timerange_label1 = new QLabel(time_timerange);
        time_timerange_label1->setObjectName(QString::fromUtf8("time_timerange_label1"));

        gridLayout_10->addWidget(time_timerange_label1, 1, 0, 1, 1);

        time_timerange_ymin = new QLineEdit(time_timerange);
        time_timerange_ymin->setObjectName(QString::fromUtf8("time_timerange_ymin"));

        gridLayout_10->addWidget(time_timerange_ymin, 3, 1, 1, 1);

        time_timerange_label2 = new QLabel(time_timerange);
        time_timerange_label2->setObjectName(QString::fromUtf8("time_timerange_label2"));

        gridLayout_10->addWidget(time_timerange_label2, 3, 0, 1, 1);

        time_timerange_auto = new QPushButton(time_timerange);
        time_timerange_auto->setObjectName(QString::fromUtf8("time_timerange_auto"));

        gridLayout_10->addWidget(time_timerange_auto, 4, 1, 1, 1);

        label_14 = new QLabel(time_timerange);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_10->addWidget(label_14, 0, 0, 1, 1);

        time_timerange_label3 = new QLabel(time_timerange);
        time_timerange_label3->setObjectName(QString::fromUtf8("time_timerange_label3"));

        gridLayout_10->addWidget(time_timerange_label3, 3, 2, 1, 1);

        time_timerange_xmin = new QLineEdit(time_timerange);
        time_timerange_xmin->setObjectName(QString::fromUtf8("time_timerange_xmin"));

        gridLayout_10->addWidget(time_timerange_xmin, 1, 1, 1, 1);

        time_timerange_label4 = new QLabel(time_timerange);
        time_timerange_label4->setObjectName(QString::fromUtf8("time_timerange_label4"));

        gridLayout_10->addWidget(time_timerange_label4, 1, 2, 1, 1);

        time_timerange_ymax = new QLineEdit(time_timerange);
        time_timerange_ymax->setObjectName(QString::fromUtf8("time_timerange_ymax"));

        gridLayout_10->addWidget(time_timerange_ymax, 3, 3, 1, 1);


        gridLayout_11->addWidget(time_timerange, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_2, 3, 0, 1, 1);

        widget_stochastic = new QWidget(tab_timeres);
        widget_stochastic->setObjectName(QString::fromUtf8("widget_stochastic"));
        widget_stochastic->setMaximumSize(QSize(16777215, 280));
        gridLayout_5 = new QGridLayout(widget_stochastic);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        time_stat_label5 = new QLabel(widget_stochastic);
        time_stat_label5->setObjectName(QString::fromUtf8("time_stat_label5"));

        gridLayout_5->addWidget(time_stat_label5, 3, 3, 1, 1);

        time_stat_result_variance = new QLineEdit(widget_stochastic);
        time_stat_result_variance->setObjectName(QString::fromUtf8("time_stat_result_variance"));

        gridLayout_5->addWidget(time_stat_result_variance, 5, 2, 1, 3);

        time_stat_start = new QPushButton(widget_stochastic);
        time_stat_start->setObjectName(QString::fromUtf8("time_stat_start"));

        gridLayout_5->addWidget(time_stat_start, 8, 4, 1, 1);

        time_stat_label3 = new QLabel(widget_stochastic);
        time_stat_label3->setObjectName(QString::fromUtf8("time_stat_label3"));

        gridLayout_5->addWidget(time_stat_label3, 2, 1, 1, 1);

        time_stat_time_et = new QLineEdit(widget_stochastic);
        time_stat_time_et->setObjectName(QString::fromUtf8("time_stat_time_et"));

        gridLayout_5->addWidget(time_stat_time_et, 3, 4, 1, 1);

        time_stat_label7 = new QLabel(widget_stochastic);
        time_stat_label7->setObjectName(QString::fromUtf8("time_stat_label7"));

        gridLayout_5->addWidget(time_stat_label7, 7, 1, 1, 1);

        time_stat_label1 = new QLabel(widget_stochastic);
        time_stat_label1->setObjectName(QString::fromUtf8("time_stat_label1"));

        gridLayout_5->addWidget(time_stat_label1, 5, 1, 1, 1);

        time_ts = new QLineEdit(widget_stochastic);
        time_ts->setObjectName(QString::fromUtf8("time_ts"));

        gridLayout_5->addWidget(time_ts, 1, 2, 1, 3);

        time_stat_label9 = new QLabel(widget_stochastic);
        time_stat_label9->setObjectName(QString::fromUtf8("time_stat_label9"));

        gridLayout_5->addWidget(time_stat_label9, 1, 1, 1, 1);

        time_stat_result_mean = new QLineEdit(widget_stochastic);
        time_stat_result_mean->setObjectName(QString::fromUtf8("time_stat_result_mean"));

        gridLayout_5->addWidget(time_stat_result_mean, 4, 2, 1, 3);

        time_stat_column = new QLineEdit(widget_stochastic);
        time_stat_column->setObjectName(QString::fromUtf8("time_stat_column"));

        gridLayout_5->addWidget(time_stat_column, 2, 2, 1, 3);

        time_stat_result_skew = new QLineEdit(widget_stochastic);
        time_stat_result_skew->setObjectName(QString::fromUtf8("time_stat_result_skew"));

        gridLayout_5->addWidget(time_stat_result_skew, 6, 2, 1, 3);

        time_stat_result_kurtosis = new QLineEdit(widget_stochastic);
        time_stat_result_kurtosis->setObjectName(QString::fromUtf8("time_stat_result_kurtosis"));

        gridLayout_5->addWidget(time_stat_result_kurtosis, 7, 2, 1, 3);

        time_stat_time_st = new QLineEdit(widget_stochastic);
        time_stat_time_st->setObjectName(QString::fromUtf8("time_stat_time_st"));

        gridLayout_5->addWidget(time_stat_time_st, 3, 2, 1, 1);

        time_stat_label8 = new QLabel(widget_stochastic);
        time_stat_label8->setObjectName(QString::fromUtf8("time_stat_label8"));
        time_stat_label8->setMaximumSize(QSize(16777215, 30));

        gridLayout_5->addWidget(time_stat_label8, 0, 1, 1, 1);

        time_stat_label4 = new QLabel(widget_stochastic);
        time_stat_label4->setObjectName(QString::fromUtf8("time_stat_label4"));

        gridLayout_5->addWidget(time_stat_label4, 3, 1, 1, 1);

        time_stat_label2 = new QLabel(widget_stochastic);
        time_stat_label2->setObjectName(QString::fromUtf8("time_stat_label2"));

        gridLayout_5->addWidget(time_stat_label2, 6, 1, 1, 1);

        time_stat_label6 = new QLabel(widget_stochastic);
        time_stat_label6->setObjectName(QString::fromUtf8("time_stat_label6"));

        gridLayout_5->addWidget(time_stat_label6, 4, 1, 1, 1);


        gridLayout_11->addWidget(widget_stochastic, 2, 0, 1, 1);

        tabWidget->addTab(tab_timeres, QString());
        tab_fft = new QWidget();
        tab_fft->setObjectName(QString::fromUtf8("tab_fft"));
        verticalLayout_4 = new QVBoxLayout(tab_fft);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_setting = new QWidget(tab_fft);
        widget_setting->setObjectName(QString::fromUtf8("widget_setting"));
        widget_setting->setMinimumSize(QSize(0, 0));
        widget_setting->setMaximumSize(QSize(16777215, 180));
        gridLayout_6 = new QGridLayout(widget_setting);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        widget_timerange = new QWidget(widget_setting);
        widget_timerange->setObjectName(QString::fromUtf8("widget_timerange"));
        widget_timerange->setMinimumSize(QSize(0, 0));
        widget_timerange->setMaximumSize(QSize(1000, 75));
        gridLayout = new QGridLayout(widget_timerange);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget_timerange);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        fft_timerange_et = new QLineEdit(widget_timerange);
        fft_timerange_et->setObjectName(QString::fromUtf8("fft_timerange_et"));

        gridLayout->addWidget(fft_timerange_et, 1, 3, 1, 1);

        fft_timerange_st = new QLineEdit(widget_timerange);
        fft_timerange_st->setObjectName(QString::fromUtf8("fft_timerange_st"));

        gridLayout->addWidget(fft_timerange_st, 1, 1, 1, 1);

        label_16 = new QLabel(widget_timerange);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 1, 0, 1, 1);

        label_6 = new QLabel(widget_timerange);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        fft_ts = new QLineEdit(widget_timerange);
        fft_ts->setObjectName(QString::fromUtf8("fft_ts"));

        gridLayout->addWidget(fft_ts, 0, 1, 1, 3);


        gridLayout_6->addWidget(widget_timerange, 5, 0, 1, 1);

        fft_timerange_ena = new QCheckBox(widget_setting);
        fft_timerange_ena->setObjectName(QString::fromUtf8("fft_timerange_ena"));

        gridLayout_6->addWidget(fft_timerange_ena, 4, 0, 1, 1);

        label_5 = new QLabel(widget_setting);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 25));

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        fft_logscaleY_on = new QCheckBox(widget_setting);
        fft_logscaleY_on->setObjectName(QString::fromUtf8("fft_logscaleY_on"));

        gridLayout_6->addWidget(fft_logscaleY_on, 1, 0, 1, 1);


        verticalLayout_4->addWidget(widget_setting);

        fft_start = new QPushButton(tab_fft);
        fft_start->setObjectName(QString::fromUtf8("fft_start"));

        verticalLayout_4->addWidget(fft_start);

        widget_freqrange = new QWidget(tab_fft);
        widget_freqrange->setObjectName(QString::fromUtf8("widget_freqrange"));
        widget_freqrange->setMaximumSize(QSize(16777215, 125));
        gridLayout_9 = new QGridLayout(widget_freqrange);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        fft_freqrange_label1 = new QLabel(widget_freqrange);
        fft_freqrange_label1->setObjectName(QString::fromUtf8("fft_freqrange_label1"));

        gridLayout_9->addWidget(fft_freqrange_label1, 1, 2, 1, 1);

        fft_freqrange_ymin = new QLineEdit(widget_freqrange);
        fft_freqrange_ymin->setObjectName(QString::fromUtf8("fft_freqrange_ymin"));

        gridLayout_9->addWidget(fft_freqrange_ymin, 2, 1, 1, 1);

        fft_freqrange_xmax = new QLineEdit(widget_freqrange);
        fft_freqrange_xmax->setObjectName(QString::fromUtf8("fft_freqrange_xmax"));

        gridLayout_9->addWidget(fft_freqrange_xmax, 1, 3, 1, 1);

        fft_freqrange_auto = new QPushButton(widget_freqrange);
        fft_freqrange_auto->setObjectName(QString::fromUtf8("fft_freqrange_auto"));

        gridLayout_9->addWidget(fft_freqrange_auto, 3, 1, 1, 1);

        fft_freqrange_label4 = new QLabel(widget_freqrange);
        fft_freqrange_label4->setObjectName(QString::fromUtf8("fft_freqrange_label4"));

        gridLayout_9->addWidget(fft_freqrange_label4, 2, 0, 1, 1);

        fft_freqrange_label2 = new QLabel(widget_freqrange);
        fft_freqrange_label2->setObjectName(QString::fromUtf8("fft_freqrange_label2"));

        gridLayout_9->addWidget(fft_freqrange_label2, 2, 2, 1, 1);

        fft_freqrange_label3 = new QLabel(widget_freqrange);
        fft_freqrange_label3->setObjectName(QString::fromUtf8("fft_freqrange_label3"));

        gridLayout_9->addWidget(fft_freqrange_label3, 1, 0, 1, 1);

        fft_freqrange_xmin = new QLineEdit(widget_freqrange);
        fft_freqrange_xmin->setObjectName(QString::fromUtf8("fft_freqrange_xmin"));

        gridLayout_9->addWidget(fft_freqrange_xmin, 1, 1, 1, 1);

        fft_freqrange_ymax = new QLineEdit(widget_freqrange);
        fft_freqrange_ymax->setObjectName(QString::fromUtf8("fft_freqrange_ymax"));

        gridLayout_9->addWidget(fft_freqrange_ymax, 2, 3, 1, 1);

        fft_freqrange_set = new QPushButton(widget_freqrange);
        fft_freqrange_set->setObjectName(QString::fromUtf8("fft_freqrange_set"));

        gridLayout_9->addWidget(fft_freqrange_set, 3, 3, 1, 1);

        label_13 = new QLabel(widget_freqrange);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_9->addWidget(label_13, 0, 0, 1, 1);


        verticalLayout_4->addWidget(widget_freqrange);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        tabWidget->addTab(tab_fft, QString());
        tab_si = new QWidget();
        tab_si->setObjectName(QString::fromUtf8("tab_si"));
        gridLayout_7 = new QGridLayout(tab_si);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget__si_start = new QWidget(tab_si);
        widget__si_start->setObjectName(QString::fromUtf8("widget__si_start"));
        verticalLayout = new QVBoxLayout(widget__si_start);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        si_start = new QPushButton(widget__si_start);
        si_start->setObjectName(QString::fromUtf8("si_start"));

        verticalLayout->addWidget(si_start);


        gridLayout_7->addWidget(widget__si_start, 1, 0, 1, 1);

        widget_si_setting = new QWidget(tab_si);
        widget_si_setting->setObjectName(QString::fromUtf8("widget_si_setting"));
        widget_si_setting->setMaximumSize(QSize(16777215, 170));
        gridLayout_12 = new QGridLayout(widget_si_setting);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        si_column_in = new QLineEdit(widget_si_setting);
        si_column_in->setObjectName(QString::fromUtf8("si_column_in"));

        gridLayout_12->addWidget(si_column_in, 1, 1, 1, 1);

        si_num_Z = new QLineEdit(widget_si_setting);
        si_num_Z->setObjectName(QString::fromUtf8("si_num_Z"));

        gridLayout_12->addWidget(si_num_Z, 4, 1, 1, 1);

        si_num_P = new QLineEdit(widget_si_setting);
        si_num_P->setObjectName(QString::fromUtf8("si_num_P"));

        gridLayout_12->addWidget(si_num_P, 3, 1, 1, 1);

        si_ts = new QLineEdit(widget_si_setting);
        si_ts->setObjectName(QString::fromUtf8("si_ts"));

        gridLayout_12->addWidget(si_ts, 0, 1, 1, 1);

        si_column_res = new QLineEdit(widget_si_setting);
        si_column_res->setObjectName(QString::fromUtf8("si_column_res"));

        gridLayout_12->addWidget(si_column_res, 2, 1, 1, 1);

        label_7 = new QLabel(widget_si_setting);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_12->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(widget_si_setting);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_12->addWidget(label_8, 1, 0, 1, 1);

        label_9 = new QLabel(widget_si_setting);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_12->addWidget(label_9, 2, 0, 1, 1);

        label_10 = new QLabel(widget_si_setting);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_12->addWidget(label_10, 3, 0, 1, 1);

        label_11 = new QLabel(widget_si_setting);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_12->addWidget(label_11, 4, 0, 1, 1);


        gridLayout_7->addWidget(widget_si_setting, 0, 0, 1, 1);

        widget_si_result = new QWidget(tab_si);
        widget_si_result->setObjectName(QString::fromUtf8("widget_si_result"));
        widget_si_result->setMaximumSize(QSize(16777215, 650));
        gridLayout_13 = new QGridLayout(widget_si_result);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        si_result_label_5 = new QLabel(widget_si_result);
        si_result_label_5->setObjectName(QString::fromUtf8("si_result_label_5"));

        gridLayout_13->addWidget(si_result_label_5, 12, 0, 1, 1);

        si_result_zero = new QTextEdit(widget_si_result);
        si_result_zero->setObjectName(QString::fromUtf8("si_result_zero"));

        gridLayout_13->addWidget(si_result_zero, 9, 1, 1, 1);

        si_result_tfz = new QTextEdit(widget_si_result);
        si_result_tfz->setObjectName(QString::fromUtf8("si_result_tfz"));

        gridLayout_13->addWidget(si_result_tfz, 2, 1, 1, 1);

        si_result_dc = new QLineEdit(widget_si_result);
        si_result_dc->setObjectName(QString::fromUtf8("si_result_dc"));

        gridLayout_13->addWidget(si_result_dc, 11, 1, 1, 1);

        si_result_label_3 = new QLabel(widget_si_result);
        si_result_label_3->setObjectName(QString::fromUtf8("si_result_label_3"));

        gridLayout_13->addWidget(si_result_label_3, 4, 0, 1, 1);

        label_2 = new QLabel(widget_si_result);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_13->addWidget(label_2, 9, 0, 1, 1);

        si_result_pole = new QTextEdit(widget_si_result);
        si_result_pole->setObjectName(QString::fromUtf8("si_result_pole"));

        gridLayout_13->addWidget(si_result_pole, 5, 1, 1, 1);

        si_result_tfs = new QTextEdit(widget_si_result);
        si_result_tfs->setObjectName(QString::fromUtf8("si_result_tfs"));

        gridLayout_13->addWidget(si_result_tfs, 4, 1, 1, 1);

        si_result_label_4 = new QLabel(widget_si_result);
        si_result_label_4->setObjectName(QString::fromUtf8("si_result_label_4"));

        gridLayout_13->addWidget(si_result_label_4, 5, 0, 1, 1);

        si_result_label_12 = new QLabel(widget_si_result);
        si_result_label_12->setObjectName(QString::fromUtf8("si_result_label_12"));

        gridLayout_13->addWidget(si_result_label_12, 11, 0, 1, 1);

        si_result_label_2 = new QLabel(widget_si_result);
        si_result_label_2->setObjectName(QString::fromUtf8("si_result_label_2"));

        gridLayout_13->addWidget(si_result_label_2, 2, 0, 1, 1);

        si_result_wn = new QLineEdit(widget_si_result);
        si_result_wn->setObjectName(QString::fromUtf8("si_result_wn"));

        gridLayout_13->addWidget(si_result_wn, 12, 1, 1, 1);


        gridLayout_7->addWidget(widget_si_result, 3, 0, 1, 1);

        tabWidget->addTab(tab_si, QString());

        verticalLayout_3->addWidget(tabWidget);


        gridLayout_4->addWidget(widget_tab, 0, 2, 1, 1);

        widget_graph = new QWidget(scrollAreaWidgetContents);
        widget_graph->setObjectName(QString::fromUtf8("widget_graph"));
        widget_graph->setMinimumSize(QSize(300, 0));
        widget_graph->setMaximumSize(QSize(16777215, 600));
        gridLayout_3 = new QGridLayout(widget_graph);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        graph_fft = new QCustomPlot(widget_graph);
        graph_fft->setObjectName(QString::fromUtf8("graph_fft"));
        graph_fft->setMinimumSize(QSize(200, 100));
        graph_fft->setMaximumSize(QSize(1000, 1000));

        gridLayout_3->addWidget(graph_fft, 1, 0, 1, 1);

        graph_si = new QCustomPlot(widget_graph);
        graph_si->setObjectName(QString::fromUtf8("graph_si"));
        graph_si->setMinimumSize(QSize(200, 100));
        graph_si->setMaximumSize(QSize(1000, 1000));

        gridLayout_3->addWidget(graph_si, 2, 0, 1, 1);

        graph_timeres = new QCustomPlot(widget_graph);
        graph_timeres->setObjectName(QString::fromUtf8("graph_timeres"));
        graph_timeres->setMinimumSize(QSize(200, 100));
        graph_timeres->setMaximumSize(QSize(1000, 1000));

        gridLayout_3->addWidget(graph_timeres, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_graph, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_14->addWidget(scrollArea, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1114, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        data_load->setText(QCoreApplication::translate("MainWindow", "Load Data", nullptr));
        data_select->setText(QCoreApplication::translate("MainWindow", "Select Data", nullptr));
        input_separator_tab->setText(QCoreApplication::translate("MainWindow", "tab", nullptr));
        input_separator_comma->setText(QCoreApplication::translate("MainWindow", "comma", nullptr));
        input_separator_space->setText(QCoreApplication::translate("MainWindow", "space", nullptr));
        button_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        time_timerange_set->setText(QCoreApplication::translate("MainWindow", "Set Range", nullptr));
        time_timerange_label1->setText(QCoreApplication::translate("MainWindow", "Time [s]", nullptr));
        time_timerange_label2->setText(QCoreApplication::translate("MainWindow", "Amplitude[-]", nullptr));
        time_timerange_auto->setText(QCoreApplication::translate("MainWindow", "Autoscale", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Plot Range", nullptr));
        time_timerange_label3->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        time_timerange_label4->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        time_stat_label5->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        time_stat_start->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        time_stat_label3->setText(QCoreApplication::translate("MainWindow", "Column", nullptr));
        time_stat_label7->setText(QCoreApplication::translate("MainWindow", "Kurtosis", nullptr));
        time_stat_label1->setText(QCoreApplication::translate("MainWindow", "Variance", nullptr));
        time_stat_label9->setText(QCoreApplication::translate("MainWindow", "Sampling time[s]", nullptr));
        time_stat_label8->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        time_stat_label4->setText(QCoreApplication::translate("MainWindow", "Time [s]", nullptr));
        time_stat_label2->setText(QCoreApplication::translate("MainWindow", "Skewness", nullptr));
        time_stat_label6->setText(QCoreApplication::translate("MainWindow", "Mean", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_timeres), QCoreApplication::translate("MainWindow", "Time", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Analazing range [s]", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Sampling time [s]", nullptr));
        fft_timerange_ena->setText(QCoreApplication::translate("MainWindow", "Time range specification", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        fft_logscaleY_on->setText(QCoreApplication::translate("MainWindow", "Use logscale Y-axis", nullptr));
        fft_start->setText(QCoreApplication::translate("MainWindow", "Start FFT", nullptr));
        fft_freqrange_label1->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        fft_freqrange_auto->setText(QCoreApplication::translate("MainWindow", "Autoscale", nullptr));
        fft_freqrange_label4->setText(QCoreApplication::translate("MainWindow", "Power [dB/-]", nullptr));
        fft_freqrange_label2->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        fft_freqrange_label3->setText(QCoreApplication::translate("MainWindow", "Freq. [Hz]", nullptr));
        fft_freqrange_set->setText(QCoreApplication::translate("MainWindow", "Set Range", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Plot Range", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_fft), QCoreApplication::translate("MainWindow", "FFT", nullptr));
        si_start->setText(QCoreApplication::translate("MainWindow", "Identify", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Sampling time [s]", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Input column", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Response column", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Number of poles", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Number of zeros", nullptr));
        si_result_label_5->setText(QCoreApplication::translate("MainWindow", "wn [Hz]", nullptr));
        si_result_label_3->setText(QCoreApplication::translate("MainWindow", "G(s)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Zeros (s)", nullptr));
        si_result_label_4->setText(QCoreApplication::translate("MainWindow", "Poles (s)", nullptr));
        si_result_label_12->setText(QCoreApplication::translate("MainWindow", "DC gain", nullptr));
        si_result_label_2->setText(QCoreApplication::translate("MainWindow", "G(z)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_si), QCoreApplication::translate("MainWindow", "Identification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
