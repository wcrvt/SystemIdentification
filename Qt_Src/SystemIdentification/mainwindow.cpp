#include "mainwindow.h"
#include "ui_mainwindow.h"


/* Constructor*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Validator
    DoubleValidator = new QDoubleValidator(this);
    DoublePosValidator = new QDoubleValidator(0.0,10000000,10,this);
    IntValidator = new QIntValidator(0,1000,this);
    NaturalValidator = new QIntValidator(1,1000,this);
    //Plot
    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);

    //Exit
    connect(ui->button_exit, SIGNAL(clicked()), this, SLOT(close()));

    //Open file
    connect(ui->data_select,SIGNAL(clicked()),this,SLOT(open_data()));
    connect(ui->data_load,SIGNAL(clicked()),this,SLOT(load_data()));
    ui->input_separator_tab->setChecked(true);

    //Table
    ui->table_data->clear();
    ui->table_data->setRowCount(DataT_ROW_INIT);
    ui->table_data->setColumnCount(DataT_COL_INIT);
    //Table::table property
    for(int i=0;i<DataT_COL_INIT;i++) ui->table_data->setColumnWidth(i,100);
    ui->table_data->verticalHeader()->setDefaultSectionSize(21);
    ui->table_data->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->table_data->setSelectionMode(QAbstractItemView::ExtendedSelection);
    //Table::color
    QPalette palette = ui->table_data->palette();
    palette.setColor(QPalette::Highlight, Qt::gray);
    palette.setColor(QPalette::HighlightedText,Qt::black);
    ui->table_data->setPalette(palette);
    connect(this,SIGNAL(load_data_fin()),this,SLOT(set_timetable()));


    //Graph: Time response
    QCustomPlot* graph_timeres=ui->graph_timeres;
    for(int gnum=0;gnum<GRAPH_MAX_NUM;gnum++) ui->graph_timeres->addGraph();
    //Graph: frame
    graph_timeres->xAxis2->setVisible(true);
    graph_timeres->xAxis2->setTickLabels(false);
    graph_timeres->yAxis2->setVisible(true);
    graph_timeres->yAxis2->setTickLabels(false);
    connect(graph_timeres->xAxis, SIGNAL(rangeChanged(QCPRange)), graph_timeres->xAxis2, SLOT(setRange(QCPRange)));
    connect(graph_timeres->yAxis, SIGNAL(rangeChanged(QCPRange)), graph_timeres->yAxis2, SLOT(setRange(QCPRange)));
    //Graph: label
    graph_timeres->xAxis->setLabel("Time [s]");
    graph_timeres->yAxis->setLabel("Response [-]");
    connect(this,SIGNAL(load_data_fin()),this,SLOT(plot_timeres()));
    connect(this,SIGNAL(load_data_fin()),this,SLOT(fft_start()));

    //Graph: Frequency response
    QCustomPlot* graph_fft=ui->graph_fft;
    for(int gnum=0;gnum<GRAPH_MAX_NUM;gnum++) ui->graph_timeres->addGraph();
    //Graph: frame
    graph_fft->xAxis2->setVisible(true);
    graph_fft->xAxis2->setTickLabels(false);
    graph_fft->yAxis2->setVisible(true);
    graph_fft->yAxis2->setTickLabels(false);
    connect(graph_fft->xAxis, SIGNAL(rangeChanged(QCPRange)), graph_fft->xAxis2, SLOT(setRange(QCPRange)));
    connect(graph_fft->yAxis, SIGNAL(rangeChanged(QCPRange)), graph_fft->yAxis2, SLOT(setRange(QCPRange)));
    //Graph: Axis
    graph_fft->xAxis->setScaleType(QCPAxis::stLogarithmic);
    graph_fft->xAxis2->setScaleType(QCPAxis::stLogarithmic);
    graph_fft->xAxis->setTicker(logTicker);
    graph_fft->xAxis2->setTicker(logTicker);
    graph_fft->xAxis->setNumberFormat("eb"); // e = exponential, b = beautiful decimal powers
    graph_fft->xAxis->setNumberPrecision(0); // makes sure "1*10^4" is displayed only as "10^4"
    graph_fft->xAxis->setRange(1e-2, 1e2);
    //Graph: label
    graph_fft->xAxis->setLabel("Frequency [Hz]");
    graph_fft->yAxis->setLabel("Power [dB/-]");

    //Graph: System identification
    QCustomPlot* graph_si=ui->graph_si;
    for(int gnum=0;gnum<GRAPH_MAX_NUM;gnum++) ui->graph_timeres->addGraph();
    //Graph: frame
    graph_si->xAxis2->setVisible(true);
    graph_si->xAxis2->setTickLabels(false);
    graph_si->yAxis2->setVisible(true);
    graph_si->yAxis2->setTickLabels(false);
    connect(graph_si->xAxis, SIGNAL(rangeChanged(QCPRange)), graph_si->xAxis2, SLOT(setRange(QCPRange)));
    connect(graph_si->yAxis, SIGNAL(rangeChanged(QCPRange)), graph_si->yAxis2, SLOT(setRange(QCPRange)));
    //Graph: Axis
    graph_si->xAxis->setScaleType(QCPAxis::stLogarithmic);
    graph_si->xAxis2->setScaleType(QCPAxis::stLogarithmic);
    graph_si->xAxis->setTicker(logTicker);
    graph_si->xAxis2->setTicker(logTicker);
    graph_si->xAxis->setNumberFormat("eb"); // e = exponential, b = beautiful decimal powers
    graph_si->xAxis->setNumberPrecision(0); // makes sure "1*10^4" is displayed only as "10^4"
    graph_si->xAxis->setRange(1e-2, 1e2);
    //Graph: label
    graph_si->xAxis->setLabel("Frequency [Hz]");
    graph_si->yAxis->setLabel("Power [dB]");

    //Data set: Time series
    DataT_ColNUM = DataT_COL_INIT;
    DataT_RowNUM = DataT_ROW_INIT;
    Data = new double* [DataT_COL_INIT];
    Data[0] = new double[DataT_ROW_INIT*DataT_COL_INIT];
    for(int n=1;n<DataT_COL_INIT;n++) Data[n]=Data[0]+n*DataT_ROW_INIT;
    for(int i=0;i<DataT_COL_INIT;i++) for(int j=0;j<DataT_ROW_INIT;j++) Data[i][j]=0.0;
    //Data set: FFT
    FFT_Power = new double* [10];
    FFT_Power[0] = new double[10*10];
    for(int n=1;n<10;n++) FFT_Power[n]=FFT_Power[0]+n*10;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) FFT_Power[i][j]=0.0;
    //Data set: Pole-zero map
    Theta=new double[10];
    for(int i=0;i<10;i++) Theta[i]=0.0;

    //Tab:Time Series
    ui->time_timerange_xmin->setValidator(DoubleValidator);
    ui->time_timerange_xmax->setValidator(DoubleValidator);
    ui->time_timerange_ymin->setValidator(DoubleValidator);
    ui->time_timerange_ymax->setValidator(DoubleValidator);
    ui->time_ts->setValidator(DoubleValidator);
    ui->time_stat_column->setValidator(NaturalValidator);
    ui->time_stat_time_st->setValidator(DoubleValidator);
    ui->time_stat_time_et->setValidator(DoubleValidator);
    ui->time_stat_result_mean->setReadOnly(true);
    ui->time_stat_result_variance->setReadOnly(true);
    ui->time_stat_result_skew->setReadOnly(true);
    ui->time_stat_result_kurtosis->setReadOnly(true);
    connect(ui->time_stat_start,SIGNAL(clicked()),this,SLOT(stat_start()));
    connect(ui->time_timerange_auto,SIGNAL(clicked()),this,SLOT(plot_timeres_autoscale()));
    connect(ui->time_timerange_set,SIGNAL(clicked()),this,SLOT(plot_timeres_setrange()));

    //Tab:FFT
    ui->fft_ts->setValidator(DoublePosValidator);
    ui->fft_timerange_st->setValidator(DoublePosValidator);
    ui->fft_timerange_et->setValidator(DoublePosValidator);
    ui->fft_logscaleY_on->setChecked(true);
    connect(ui->fft_start,SIGNAL(clicked()),this,SLOT(fft_start()));
    connect(this,SIGNAL(fft_end()),this,SLOT(plot_fft()));
    connect(this,SIGNAL(fft_end()),this,SLOT(plot_si()));
    connect(ui->fft_freqrange_auto,SIGNAL(clicked()),this,SLOT(plot_fft_autoscale()));
    connect(ui->fft_freqrange_set,SIGNAL(clicked()),this,SLOT(plot_fft_setrange()));

    //Tab:PZmap
    ui->si_ts->setValidator(DoublePosValidator);
    ui->si_column_in->setValidator(NaturalValidator);
    ui->si_column_res->setValidator(NaturalValidator);
    ui->si_num_P->setValidator(NaturalValidator);
    ui->si_num_Z->setValidator(IntValidator);
    ui->si_result_pole->setReadOnly(true);
    ui->si_result_zero->setReadOnly(true);
    ui->si_result_tfz->setReadOnly(true);
    ui->si_result_tfs->setReadOnly(true);
    ui->si_result_wn->setReadOnly(true);
    ui->si_result_dc->setReadOnly(true);
    connect(ui->si_start,SIGNAL(clicked()),this,SLOT(pz_lsm_start()));
    connect(this,SIGNAL(pz_getmodl_fin()),this,SLOT(pz_get_pz()));
    connect(this,SIGNAL(pz_getpz_fin()),this,SLOT(plot_si()));
/*
    //Tab:Save
    connect(ui->save_data,SIGNAL(clicked()),this,SLOT(save_data()));
*/
}

/* Destructor */
MainWindow::~MainWindow()
{
    delete ui;
    delete DoubleValidator;
    delete DoublePosValidator;
    delete IntValidator;
    delete NaturalValidator;
    delete[] Data[0];
    delete[] Data;
    delete[] FFT_Power[0];
    delete[] FFT_Power;
    delete Theta;
}


/* Plot time response */
void MainWindow::plot_timeres(){

    QCustomPlot* graph = ui->graph_timeres;
    int Graph_NUM = ((DataT_ColNUM-1)>GRAPH_MAX_NUM)? GRAPH_MAX_NUM:DataT_ColNUM-1;
    int plData_ColNUM=Graph_NUM+1;

    QVector<QVector<double>> plData_timeres(plData_ColNUM, QVector<double>(DataT_RowNUM));
    for (int i=0;i<plData_ColNUM;i++) for(int j=0;j<DataT_RowNUM;j++) plData_timeres[i][j] =Data[i][j];

    //Reset Graphs
    for(int gnum=0;gnum<GRAPH_MAX_NUM;gnum++){ graph->removeGraph(gnum); graph->addGraph(); }

    //Graph: line color
    int Coloring_NUM=((DataT_ColNUM-1)>LineColor.size())? LineColor.size():DataT_ColNUM-1;
    for(int plnum=0;plnum<Coloring_NUM;plnum++) graph->graph(plnum)->setPen(QPen(LineColor[plnum]));

    //Set the plot data
    for(int plnum=0;plnum<Graph_NUM;plnum++) graph->graph(plnum)->setData(plData_timeres[0], plData_timeres[plnum+1]);

    //Rescaling the graph range...force replacing and then optional replacing if needed, then plot
    graph->graph(0)->rescaleAxes();
    for(int gnum=1;gnum<Graph_NUM;gnum++) graph->graph(gnum)->rescaleAxes(true);
    graph->replot();

}

/* Plot time responnse: autoscale */
void MainWindow::plot_timeres_autoscale(){

    QCustomPlot* graph = ui->graph_timeres;
    int Graph_NUM = ((DataT_ColNUM-1)>GRAPH_MAX_NUM)? GRAPH_MAX_NUM:DataT_ColNUM-1;
    graph->graph(0)->rescaleAxes();
    for(int gnum=1;gnum<Graph_NUM;gnum++) graph->graph(gnum)->rescaleAxes(true);
    graph->replot();

}

/* Plot time responnse: set range */
void MainWindow::plot_timeres_setrange(){

    QCustomPlot* graph = ui->graph_timeres;
    int xset_validator=(ui->time_timerange_xmin->text()!="\0" && ui->time_timerange_xmax->text()!="\0")? 1:0;
    int yset_validator=(ui->time_timerange_ymin->text()!="\0" && ui->time_timerange_ymax->text()!="\0")? 1:0;
    double xmin=ui->time_timerange_xmin->text().toDouble();
    double xmax=ui->time_timerange_xmax->text().toDouble();
    double ymin=ui->time_timerange_ymin->text().toDouble();
    double ymax=ui->time_timerange_ymax->text().toDouble();
    if( (xset_validator&&(xmin>=xmax)) || (yset_validator&&(ymin>=ymax)) ){
        QMessageBox::critical(this, tr("Error"), tr("Set valid value"));
        return;
    }
    if(xset_validator) graph->xAxis->setRange(xmin, xmax);
    if(yset_validator) graph->yAxis->setRange(ymin, ymax);

    graph->replot();

}

/* Plot frequency response */
void MainWindow::plot_fft(){

    QCustomPlot* graph = ui->graph_fft;
    int Graph_NUM = ((DataT_ColNUM-1)>GRAPH_MAX_NUM)? GRAPH_MAX_NUM:DataT_ColNUM-1;
    int plData_ColNUM=Graph_NUM+1;


    QVector<QVector<double>> plData_fft(plData_ColNUM, QVector<double>(FFT_PlotNum));
    for(int j=0;j<FFT_PlotNum;j++) plData_fft[0][j] = FFT_Power[0][j];
    for (int i=1;i<plData_ColNUM;i++) for(int j=0;j<FFT_PlotNum;j++){
        if(ui->fft_logscaleY_on->isChecked()){ if(FFT_Power[i][j]>0.0) plData_fft[i][j]=20*log10(FFT_Power[i][j]); }
        else plData_fft[i][j]=FFT_Power[i][j];
    }

    //Reset Graphs
    for(int gnum=0;gnum<GRAPH_MAX_NUM;gnum++){ graph->removeGraph(gnum); graph->addGraph(); }

    //Graph: line color
    int Coloring_NUM=((DataT_ColNUM-1)>LineColor.size())? LineColor.size():DataT_ColNUM-1;
    for(int plnum=0;plnum<Coloring_NUM;plnum++) graph->graph(plnum)->setPen(QPen(LineColor[plnum]));

    //Set the plot data
    for(int plnum=0;plnum<Graph_NUM;plnum++) graph->graph(plnum)->setData(plData_fft[0], plData_fft[plnum+1]);

    //Rescaling the graph range...force replacing and then optional replacing if needed, then plot
    graph->graph(0)->rescaleAxes();
    for(int gnum=1;gnum<Graph_NUM;gnum++) graph->graph(gnum)->rescaleAxes(true);
    graph->replot();

}

/* Plot frequency responnse: autoscale */
void MainWindow::plot_fft_autoscale(){

    QCustomPlot* graph = ui->graph_fft;
    int Graph_NUM=((DataT_ColNUM-1)>GRAPH_MAX_NUM)? GRAPH_MAX_NUM:DataT_ColNUM-1;
    if(FFT_ON){
        graph->graph(0)->rescaleAxes();
        for(int gnum=1;gnum<Graph_NUM;gnum++) graph->graph(gnum)->rescaleAxes(true);
    }
    graph->replot();

}

/* Plot frequency responnse: set range */
void MainWindow::plot_fft_setrange(){

    QCustomPlot* graph = ui->graph_fft;
    int xset_validator=(ui->fft_freqrange_xmin->text()!="\0" && ui->fft_freqrange_xmax->text()!="\0")? 1:0;
    int yset_validator=(ui->fft_freqrange_ymin->text()!="\0" && ui->fft_freqrange_ymin->text()!="\0")? 1:0;
    double xmin=ui->fft_freqrange_xmin->text().toDouble();
    double xmax=ui->fft_freqrange_xmax->text().toDouble();
    double ymin=ui->fft_freqrange_ymin->text().toDouble();
    double ymax=ui->fft_freqrange_ymax->text().toDouble();
    if(xmin==0.0) xmin=1e-12;
    if( (xset_validator&&(xmin>=xmax)) || (yset_validator&&(ymin>=ymax)) ){
        QMessageBox::critical(this, tr("Error"), tr("Set valid value"));
        return;
    }
    if(xset_validator) graph->xAxis->setRange(xmin, xmax);
    if(yset_validator) graph->yAxis->setRange(ymin, ymax);
    graph->replot();

}

/* Plot Bode plot of the identified model */
void MainWindow::plot_si(){

    QCustomPlot* graph = ui->graph_si;
    int Graph_A_NUM = 1;
    int Graph_B_NUM = 1;
    int Graph_NUM = Graph_A_NUM + Graph_B_NUM;
    int plData_A_ColNUM=Graph_A_NUM+1;
    int plData_B_ColNUM=Graph_B_NUM+1;

    QVector<QVector<double>> plData_fft_A(plData_A_ColNUM, QVector<double>(FFT_PlotNum));
    QVector<QVector<double>> plData_fft_B(plData_B_ColNUM, QVector<double>(BODE_ITERATION));

    int FFT_plot_valid=0;
    XData_INDICATOR=ui->si_column_res->text().toInt()-1;
    UData_INDICATOR=ui->si_column_in->text().toInt()-1;
    if(ui->si_column_in->text()=="\0") UData_INDICATOR=0;
    if(ui->si_column_res->text()=="\0") XData_INDICATOR=0;
    if(XData_INDICATOR<=FFT_DATA_NUM && UData_INDICATOR<=FFT_DATA_NUM) FFT_plot_valid=1;
    if(UData_INDICATOR==0 || XData_INDICATOR==0) FFT_plot_valid=0;
    FFT_plot_valid &= FFT_ON;

    double si_power=0.0;

    if(FFT_plot_valid){
        for(int i=0;i<FFT_PlotNum;i++){
            si_power=FFT_Power[XData_INDICATOR][i]/FFT_Power[UData_INDICATOR][i];
            if(si_power>0.0){
                plData_fft_A[0][i] =FFT_Power[0][i];
                plData_fft_A[1][i]=20.0*log10(si_power);
            }
        }
    }

    // Get Bode Plot
    const double dw=(M_PI/PZ_TS)/BODE_ITERATION;
    const complexf z_init(1.0, 0.0);
    const complexf dz=exp(complexf(0.0,dw)*PZ_TS);
    double w=0.0;
    complexf z;

    double z_gain;
    complexf z_numer, z_denom;

    complexf *za,*zb;
    za=new complexf[NUM_POLES+1];
    zb=new complexf[NUM_ZEROS+1];

    za[0]=1.0;
    for(int i=1;i<NUM_POLES+1;i++) za[i]=-Theta[i-1];
    for(int i=0;i<NUM_ZEROS+1;i++) zb[i]=Theta[NUM_POLES+i];

    z=z_init;
    for(int lp=0;lp<BODE_ITERATION;lp++){
        z_numer=0.0; z_denom=0.0;
        for(int i=0;i<NUM_POLES+1;i++) z_denom+=za[i]*pow(z,NUM_POLES-i);
        for(int i=0;i<NUM_ZEROS+1;i++) z_numer+=zb[i]*pow(z,NUM_ZEROS-i);
        z_gain=abs(z_numer/z_denom);
        if(z_gain>0.0){
            plData_fft_B[0][lp]=w/(2.0*M_PI);
            plData_fft_B[1][lp]=20*log10(z_gain);
        }
        z*=dz;
        w+=dw;
    }

    delete za;
    delete zb;

    //Reset Graphs
    for(int gnum=0;gnum<GRAPH_MAX_NUM;gnum++){ graph->removeGraph(gnum); graph->addGraph(); }

    //Graph: line color
    int Coloring_NUM=((DataT_ColNUM-1)>LineColor.size())? LineColor.size():DataT_ColNUM-1;
    for(int plnum=0;plnum<Coloring_NUM;plnum++) graph->graph(plnum)->setPen(QPen(LineColor[plnum]));

    //Set the plot data
    graph->graph(0)->setData(plData_fft_A[0], plData_fft_A[1]);
    graph->graph(1)->setData(plData_fft_B[0], plData_fft_B[1]);

    //Rescaling the graph range...force replacing and then optional replacing if needed, then plot
    graph->graph(0)->rescaleAxes();
    for(int gnum=1;gnum<Graph_NUM;gnum++) graph->graph(gnum)->rescaleAxes(true);
    graph->replot();

}

/* Start Statistic Calculation*/
void MainWindow::stat_start(){

    int stat_datanum_start=0;
    int stat_datanum_end=0;

    SI_TS=ui->time_ts->text().toDouble();
    if(!(SI_TS>0.0)){ QMessageBox::critical(this, tr("Error"), tr("Set valid value Ts")); return;}

    if(ui->time_stat_column->text()=="\0"){ QMessageBox::critical(this, tr("Error"), tr("Please set a column number")); return;}
    int stat_column=ui->time_stat_column->text().toInt()-1;
    if(stat_column<0||stat_column>=DataT_ColNUM){
        QMessageBox::critical(this, tr("Error"), tr("Invalid column number was set"));
        return;
    }

    //Time specification
    double stat_time_max = static_cast<double>(DataT_RowNUM-1)*SI_TS;
    double stat_time_start=0.0;
    double stat_time_end=0.0;
    if(ui->time_stat_time_st->text()=="\0" || ui->time_stat_time_et->text()=="\0"){
        QMessageBox::critical(this, tr("Error"), tr("Please set an time interval to be analized."));
        return;
    }
    stat_time_start = ui->time_stat_time_st->text().toDouble();
    stat_time_end = ui->time_stat_time_et->text().toDouble();
    //...and Validation
    if(stat_time_max<stat_time_end){ QMessageBox::critical(this, tr("Error"), tr("End time passes the total time")); return;}
    if(stat_time_max<stat_time_start){ QMessageBox::critical(this, tr("Error"), tr("Start time passes the end time")); return;}
    //...then Set
    stat_datanum_start=static_cast<int>(stat_time_start/SI_TS)+1;
    stat_datanum_end=static_cast<int>(stat_time_end/SI_TS)+1;
    int stat_datanum_use = stat_datanum_end-stat_datanum_start+1;

    double mean=0.0;
    double error_from_mean=0.0;
    double stdev=0.0;
    double variance=0.0;
    double skewness=0.0;
    double kurtosis=0.0;

    for(int i=0; i<stat_datanum_use; i++) mean += Data[stat_column][i+stat_datanum_start-1];
    mean/=stat_datanum_use;

    for(int i=0; i<stat_datanum_use; i++){
        error_from_mean=Data[stat_column][i+stat_datanum_start-1]-mean;
        variance += pow(error_from_mean,2.0);
        skewness += pow(error_from_mean,3.0);
        kurtosis += pow(error_from_mean,4.0);
    }

    double n=static_cast<double>(stat_datanum_use);
    variance /= n;
    stdev = sqrt(variance);
    skewness *= n/(n-1)/(n-2)/pow(stdev,3.0);
    kurtosis *= n*(n+1)/(n-1)/(n-2)/(n-3)/pow(stdev,4.0);
    kurtosis -= 3.0*pow(n-1.0,2.0)/(n-2.0)/(n-3.0);

    ui->time_stat_result_mean->setText(QString::number(mean));
    ui->time_stat_result_variance->setText(QString::number(variance));
    ui->time_stat_result_skew->setText(QString::number(skewness));
    ui->time_stat_result_kurtosis->setText(QString::number(kurtosis));

}


/* Start FFT */
void MainWindow::fft_start(){

    FFT_TS=ui->fft_ts->text().toDouble();
    if(!(FFT_TS>0.0)){ QMessageBox::critical(this, tr("Error"), tr("Set valid value Ts")); return;}

    double fft_time_max = static_cast<double>(DataT_RowNUM-1)*FFT_TS;
    double fft_time_start = 0.0;
    double fft_time_end = 0.0;
    int fft_datanum_start = 0.0;
    int fft_datanum_end =0.0;

    FFT_DATA_NUM = ((DataT_ColNUM-1)>FFT_MAX_NUM)? FFT_MAX_NUM:DataT_ColNUM-1;
    int fft_datanum_column = FFT_DATA_NUM+1;

    if(ui->fft_timerange_ena->isChecked()){
        //Specification
        if(ui->fft_timerange_st->text()=="\0" || ui->fft_timerange_et->text()=="\0"){
            QMessageBox::critical(this, tr("Error"), tr("Please set an interval to be analized."));
            return;
        }
        fft_time_start = ui->fft_timerange_st->text().toDouble();
        fft_time_end = ui->fft_timerange_et->text().toDouble();
        //...and Validation
        if(fft_time_max<fft_time_end){ QMessageBox::critical(this, tr("Error"), tr("End time passes the total time.")); return;}
        if(fft_time_end<fft_time_start){ QMessageBox::critical(this, tr("Error"), tr("Start time passes the end time.")); return;}
        //...then Set
        fft_datanum_start=static_cast<int>(fft_time_start/FFT_TS)+1;
        fft_datanum_end=static_cast<int>(fft_time_end/FFT_TS)+1;
    }else{
        //Set
        fft_datanum_start=1;
        fft_datanum_end=DataT_RowNUM;
    }
    int fft_datanum_use = fft_datanum_end-fft_datanum_start+1;
    FFT_PlotNum = static_cast<int>(fft_datanum_use/2);

    //Release secured area (if any) and re-secure new area
    delete[] FFT_Power[0];
    delete[] FFT_Power;
    FFT_Power = new double* [fft_datanum_column];
    FFT_Power[0] = new double[fft_datanum_column*fft_datanum_use];
    for(int n=1;n<fft_datanum_column;n++) FFT_Power[n]=FFT_Power[0]+n*fft_datanum_use;

    //set x-axis (frequency)
    for (int i=0; i<fft_datanum_use; i++) FFT_Power[0][i] = static_cast<double>(i)/(fft_datanum_use*FFT_TS);

    for(int fftnum=0; fftnum<FFT_DATA_NUM; fftnum++){

        // Set N to the number of complex elements in the input array
        fftw_complex *in, *out;
        in = static_cast<fftw_complex *>(fftw_malloc(sizeof(fftw_complex) * static_cast<unsigned long>(fft_datanum_use)));
        out = static_cast<fftw_complex *>(fftw_malloc(sizeof(fftw_complex) * static_cast<unsigned long>(fft_datanum_use)));


        // Initialize 'in' with N complex entries
        for (int i=0; i<fft_datanum_use; i++){
            in[i][0] = Data[fftnum+1][i+fft_datanum_start-1]/fft_datanum_use;
            in[i][1] = 0.0;
        }

        fftw_plan my_plan;
        my_plan = fftw_plan_dft_1d(fft_datanum_use, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
        fftw_execute(my_plan);

        // Use 'out' for something
        for (int i=0; i<fft_datanum_use; i++) FFT_Power[fftnum+1][i] = 2.0*sqrt(pow(out[i][0],2.0)+pow(out[i][1],2.0));

        fftw_free(in);
        fftw_free(out);
    }

    FFT_ON=1;
    emit(fft_end());

}

/* Start PZ map: Least Square method start */
void MainWindow::pz_lsm_start(){

    PZ_TS=ui->si_ts->text().toDouble();
    if(!(PZ_TS>0.0)){ QMessageBox::critical(this, tr("Error"), tr("Set valid value Ts")); return;}

    if(ui->si_num_P->text()=="\0"||ui->si_num_Z->text()=="\0"){ QMessageBox::critical(this, tr("Error"), tr("Set values")); return;}
    NUM_POLES=ui->si_num_P->text().toInt();
    NUM_ZEROS=ui->si_num_Z->text().toInt();

    XData_INDICATOR=ui->si_column_res->text().toInt()-1;
    UData_INDICATOR=ui->si_column_in->text().toInt()-1;
    if(XData_INDICATOR<0 || XData_INDICATOR>=DataT_ColNUM || UData_INDICATOR<0 || UData_INDICATOR>=DataT_ColNUM){
        QMessageBox::critical(this, tr("Error"), tr("Invalid column was specified."));
        return;
    }

    int NUM_POLES_COEFF=NUM_POLES;
    int NUM_ZEROS_COEFF=NUM_ZEROS+1;
    int NUM_PZS_COEFF=NUM_POLES_COEFF+NUM_ZEROS_COEFF;
    if(NUM_POLES_COEFF==0){ QMessageBox::critical(this, tr("Error"), tr("Number of Poles should be larger than 0.")); return;}

    delete Theta;
    Theta=new double[NUM_PZS_COEFF];

    double x=0.0, u=0.0;
    double zx=0.0,zu=0.0;
    double diag_buf=0.0;

    double *x_vec,*u_vec, *phi, *Phi, **Psi, **invPsi;
    x_vec=new double[NUM_POLES_COEFF];
    u_vec=new double[NUM_ZEROS_COEFF];
    phi=new double[NUM_PZS_COEFF];
    Phi=new double[NUM_PZS_COEFF];
    Psi=new double*[NUM_PZS_COEFF];
    Psi[0]=new double[NUM_PZS_COEFF*NUM_PZS_COEFF];
    for(int i=1;i<NUM_PZS_COEFF;i++)Psi[i]=Psi[0]+i*NUM_PZS_COEFF;
    invPsi=new double*[NUM_PZS_COEFF];
    invPsi[0]=new double[NUM_PZS_COEFF*NUM_PZS_COEFF];
    for(int i=1;i<NUM_PZS_COEFF;i++) invPsi[i]=invPsi[0]+i*NUM_PZS_COEFF;
    for(int i=0;i<NUM_PZS_COEFF;i++) for(int j=0;j<NUM_PZS_COEFF;j++)  invPsi[i][j]=0.0;

    //Initialization
    zx=0.0; zu=0.0;
    for(int i=0;i<NUM_POLES_COEFF;i++) x_vec[i]=0.0;
    for(int i=0;i<NUM_ZEROS_COEFF;i++) u_vec[i]=0.0;
    for(int i=0;i<NUM_PZS_COEFF;i++) Theta[i]=0.0;
    for(int i=0;i<NUM_PZS_COEFF;i++) phi[i]=0.0;
    for(int i=0;i<NUM_PZS_COEFF;i++) Phi[i]=0.0;
    for(int i=0;i<NUM_PZS_COEFF;i++) for(int j=0;j<NUM_PZS_COEFF;j++)  Psi[i][j]=0.0;
    for(int i=0;i<NUM_PZS_COEFF;i++) for(int j=0;j<NUM_PZS_COEFF;j++)  invPsi[i][j]=0.0;

    for(int rnum=0;rnum<DataT_RowNUM;rnum++){
        x=Data[XData_INDICATOR][rnum]; u=Data[UData_INDICATOR][rnum];
        for(int i=NUM_POLES_COEFF-1;i>0;i--) x_vec[i]=x_vec[i-1]; x_vec[0]=zx;
        for(int i=NUM_ZEROS_COEFF-1;i>0;i--) u_vec[i]=u_vec[i-1]; u_vec[0]=zu;
        for(int i=0;i<NUM_POLES_COEFF;i++) phi[i]=x_vec[i];
        for(int i=0;i<NUM_ZEROS_COEFF;i++) phi[NUM_POLES_COEFF+i]=u_vec[i];
        for(int i=0;i<NUM_PZS_COEFF;i++) Phi[i]+=x*phi[i];
        for(int i=0;i<NUM_PZS_COEFF;i++) for(int j=0;j<NUM_PZS_COEFF;j++) Psi[i][j]+=phi[i]*phi[j];
        zx=x;zu=u;
    }

    for(int i=0; i<NUM_PZS_COEFF; i++) invPsi[i][i] = 1.0;
    for(int i=0; i<NUM_PZS_COEFF; i++){
        if(Psi[i][i]==0.0) Psi[i][i]=1e-12;
        diag_buf = 1.0/Psi[i][i];
        for(int j=0; j<NUM_PZS_COEFF; j++){ Psi[i][j] *= diag_buf; invPsi[i][j] *= diag_buf; }
        for(int j=0; j<NUM_PZS_COEFF; j++){
            if(i!=j){
                diag_buf = Psi[j][i];
                for(int k=0; k<NUM_PZS_COEFF; k++){ Psi[j][k]-=Psi[i][k]*diag_buf; invPsi[j][k]-=invPsi[i][k]*diag_buf; }
            }
        }
    }

    for(int i=0;i<NUM_PZS_COEFF;i++) for(int j=0;j<NUM_PZS_COEFF;j++) Theta[i]+=invPsi[i][j]*Phi[j];

    delete x_vec;
    delete u_vec;
    delete phi;
    delete Phi;
    delete[] Psi[0];
    delete[] Psi;
    delete[] invPsi[0];
    delete[] invPsi;

    QString Gz_numer="\0";
    QString Gz_denom="\0";
    QString vinculum="--------------------------------";
    QString sign;
    QString zoperator;

    for(int i=0;i<NUM_ZEROS_COEFF;i++){
        sign=(Theta[NUM_POLES_COEFF+i]>=0.0)? "+":"\0";
        zoperator=(i==0)? "\0":QString("z^(%1)").arg(-i);
        Gz_numer=Gz_numer+sign+QString::number(Theta[NUM_POLES_COEFF+i])+zoperator;
    }

    for(int i=0;i<NUM_POLES_COEFF;i++){
        sign=(-Theta[i]>=0.0)? "+":"\0";
        zoperator=QString("z^(%1)").arg(-(i+1));
        Gz_denom=Gz_denom+sign+QString::number(-Theta[i])+zoperator;
    }
    Gz_denom=QString("1.0")+Gz_denom;

    double Gz_gain_numer=0.0;
    double Gz_gain_denom=0.0;

    Gz_gain_denom=1.0; Gz_gain_numer=0.0;
    for(int i=0;i<NUM_ZEROS_COEFF;i++) Gz_gain_numer += Theta[NUM_POLES_COEFF+i];
    for(int i=0;i<NUM_POLES_COEFF;i++) Gz_gain_denom += -Theta[i];

    GZ_GAIN=Gz_gain_numer/Gz_gain_denom;

    QString Gz_tf=Gz_numer+"\n"+vinculum+"\n"+Gz_denom;
    QString Gz_gain = QString::number(GZ_GAIN) +" (=1.0/"+ QString::number(Gz_gain_denom/Gz_gain_numer) +")";

    ui->si_result_tfz->setText(Gz_tf);
    ui->si_result_dc->setText(Gz_gain);

    emit(pz_getmodl_fin());

}

/* Start PZ map: Get poles */
void MainWindow::pz_get_pz(){

    int pole_degree=NUM_POLES;

    const complexf I(0.0, 1.0);
    complexf tmp=0.0;

    complexf pole_root_cog;
    double pole_coeff_max=0.0;
    double pole_R=0.0;
    double pole_error=0.0;

    complexf pole_dv_numer,pole_dv_denom;
    complexf *pole_a,*pole_z, *pole_s;
    pole_a=new complexf[pole_degree+1];
    pole_z=new complexf[pole_degree];
    pole_s=new complexf[pole_degree];

    int pole_num_wn=0;
    int pole_num_wn_cnt=0;
    double *pole_w;
    pole_w=new double[pole_degree];

    pole_a[0]=1.0;
    for(int i=1;i<pole_degree+1;i++) pole_a[i]=-Theta[i-1];

    if(pole_degree==0){
        ui->si_result_pole->setText("--");
        ui->si_result_wn->setText("--");
    }else{
        //Make the function be monic
        for (int i=1; i<=pole_degree; i++) pole_a[i] /= pole_a[0];
        pole_a[0]=1.0;

        //Initialization
        pole_root_cog=-pole_a[1]/static_cast<double>(pole_degree);
        pole_coeff_max=0.0;
        for (int i = 1; i<=pole_degree; i++) if(abs(pole_a[i])>pole_coeff_max) pole_coeff_max=abs(pole_a[i]);
        pole_R=abs(pole_root_cog)+1+pole_coeff_max;
        for (int i=0; i<pole_degree; i++) pole_z[i] = pole_root_cog+pole_R*exp(I*(2.0*i*M_PI/pole_degree + M_PI/ (2.0*pole_degree)));

        for(int i=1; i<DKA_ITERATION_NUM; i++){
            pole_error=0;
            for (int j=0; j<pole_degree; j++) {
                pole_dv_numer=1.0;
                pole_dv_denom=1.0;
                for(int k=0; k<pole_degree; k++){
                    pole_dv_numer=pole_dv_numer*pole_z[j]+pole_a[k+1];
                    if(k!=j) pole_dv_denom*=(pole_z[j]-pole_z[k]);
                }
                pole_z[j]-=pole_dv_numer/pole_dv_denom;
                pole_error+=abs(pole_dv_numer/pole_dv_denom);
            }
            if(pole_error<1e-12)	i=DKA_ITERATION_NUM;
        }

        for(int i=0; i<pole_degree; i++) pole_s[i]=log(pole_z[i])/PZ_TS;

        //Sorting Poles
        for (int i=0; i<pole_degree; i++){
            for (int j=i+1; j<pole_degree; j++){
                if (abs(pole_s[i]) > abs(pole_s[j])){
                    tmp =  pole_s[i];
                    pole_s[i] = pole_s[j];
                    pole_s[j] = tmp;
                }
            }
        }

        QString poles, pole, pole_real, pole_imag;
        QString sign, separator;
        poles="\0";
        for(int i=0; i<pole_degree; i++){
            pole_real=(fabs(pole_s[i].real())>PZ_TRUNCATE)? QString::number(pole_s[i].real(),PZ_FORMAT,PZ_DIGIT):"\0";
            pole_imag=(fabs(pole_s[i].imag())>PZ_TRUNCATE)? QString::number(pole_s[i].imag(),PZ_FORMAT,PZ_DIGIT)+"i":"\0";
            sign=(pole_s[i].imag()>0.0 && fabs(pole_s[i].imag())>PZ_TRUNCATE && fabs(pole_s[i].real())>PZ_TRUNCATE)? "+":"\0";
            pole=pole_real+sign+pole_imag;
            pole=(pole=="\0")? QString::number(0.0,PZ_FORMAT,PZ_DIGIT):pole;
            separator=(i==pole_degree-1)? "\0":",\n";
            poles+=pole+separator;
        }
        ui->si_result_pole->setText(poles);

        for(int i=0; i<pole_degree; i++) pole_w[i]=abs(pole_s[i])/(2.0*M_PI);
        for(int i=0; i<pole_degree; i++) for(int j=i+1;j<pole_degree;j++) pole_w[j]=(fabs(pole_w[j]-pole_w[i])<PZ_WN_WIDTH_MIN)? 0.0:pole_w[j];

        pole_num_wn=0;
        for(int i=0; i<pole_degree; i++) if(pole_w[i]>PZ_WN_MIN) pole_num_wn++;

        QString wns, wn;
        wns="\0";

        pole_num_wn_cnt=0;
        for(int i=0; i<pole_degree; i++){
            wn=(pole_w[i]>PZ_WN_MIN)? QString::number(pole_w[i],PZ_FORMAT,PZ_DIGIT):"\0";
            if(pole_w[i]>PZ_WN_MIN) pole_num_wn_cnt++;
            if(pole_w[i]>PZ_WN_MIN) separator=(pole_num_wn_cnt==pole_num_wn)? "\0":", "; else separator="\0";
            wns+=wn+separator;
        }

        ui->si_result_wn->setText(wns);

    }

    int zero_degree=NUM_ZEROS;

    complexf zero_root_cog;
    double zero_coeff_max=0.0;
    double zero_R=0.0;
    double zero_error=0.0;

    complexf zero_dv_numer,zero_dv_denom;
    complexf *zero_a,*zero_z, *zero_s;
    zero_a=new complexf[zero_degree+1];
    zero_z=new complexf[zero_degree];
    zero_s=new complexf[zero_degree];


    for(int i=0;i<zero_degree+1;i++) zero_a[i]=Theta[NUM_POLES+i];

    if(zero_degree==0){
        ui->si_result_zero->setText("--");
    }else{
        //Make the function be monic
        for (int i=1; i <=zero_degree; i++) zero_a[i] /= zero_a[0];
        zero_a[0]=1.0;

        //Initialization
        zero_root_cog=-zero_a[1]/static_cast<double>(zero_degree);
        zero_coeff_max=0.0;
        for (int i = 1; i<=zero_degree; i++) if(abs(zero_a[i])>zero_coeff_max) zero_coeff_max=abs(zero_a[i]);
        zero_R=abs(zero_root_cog)+1+zero_coeff_max;
        for (int i=0; i<zero_degree; i++) zero_z[i] = zero_root_cog+zero_R*exp(I*(2.0*i*M_PI/zero_degree + M_PI/ (2.0*zero_degree)));

        for(int i=1; i<DKA_ITERATION_NUM; i++){
            zero_error=0;
            for (int j=0; j<zero_degree; j++) {
                zero_dv_numer=1.0;
                zero_dv_denom=1.0;
                for(int k=0; k<zero_degree; k++){
                    zero_dv_numer=zero_dv_numer*zero_z[j]+zero_a[k+1];
                    if(k!=j) zero_dv_denom*=(zero_z[j]-zero_z[k]);
                }
                zero_z[j]-=zero_dv_numer/zero_dv_denom;
                zero_error+=abs(zero_dv_numer/zero_dv_denom);
            }
            if(zero_error<1e-12) i=DKA_ITERATION_NUM;
        }

        for(int i=0; i<zero_degree; i++) zero_s[i]=log(zero_z[i])/PZ_TS;

        //Sorting Zeros
        for (int i=0; i<zero_degree; i++){
            for (int j=i+1; j<zero_degree; j++){
                if (abs(zero_s[i]) > abs(zero_s[j])){
                    tmp =  zero_s[i];
                    zero_s[i] = zero_s[j];
                    zero_s[j] = tmp;
                }
            }
        }

        QString zeros, zero, zero_real, zero_imag;
        QString sign, separator;
        zeros="\0";
        for(int i=0; i<zero_degree; i++){
            zero_real=(fabs(zero_s[i].real())>PZ_TRUNCATE)? QString::number(zero_s[i].real(),PZ_FORMAT,PZ_DIGIT):"\0";
            zero_imag=(fabs(zero_s[i].imag())>PZ_TRUNCATE)? QString::number(zero_s[i].imag(),PZ_FORMAT,PZ_DIGIT)+"i":"\0";
            sign=(zero_s[i].imag()>0.0 && fabs(zero_s[i].imag())>PZ_TRUNCATE && fabs(zero_s[i].real())>PZ_TRUNCATE)? "+":"\0";
            zero=zero_real+sign+zero_imag;
            zero=(zero=="\0")? QString::number(0.0,PZ_FORMAT,PZ_DIGIT):zero;
            separator=(i==zero_degree-1)? "\0":",\n";
            zeros+=zero+separator;
        }

        ui->si_result_zero->setText(zeros);

    }

    complexf *pole_root;
    complexf *zero_root;
    pole_root=new complexf[APPROX_ORDER];
    zero_root=new complexf[APPROX_ORDER];
    for(int i=0;i<APPROX_ORDER;i++){ pole_root[i]=0.0; zero_root[i]=0.0; };

    complexf *pole_coeff;
    complexf *zero_coeff;
    pole_coeff=new complexf[APPROX_ORDER];
    zero_coeff=new complexf[APPROX_ORDER];
    for(int i=0;i<APPROX_ORDER;i++){ pole_coeff[i]=0.0; zero_coeff[i]=0.0; };

    complexf pole_coeff_sum=0.0;
    complexf zero_coeff_sum=0.0;
    int pole_coeff_num=0;
    int zero_coeff_num=0;

    complexf pole_product_wn=0.0;
    complexf zero_product_wn=0.0;
    double Gs_gain_untuned=0.0;
    double Gs_gain_conv=0.0;


    if( pole_degree<=APPROX_ORDER && zero_degree<=APPROX_ORDER ){

        for(int i=0; i<zero_degree; i++) zero_root[i]=zero_s[i];
        for(int i=0; i<pole_degree; i++) pole_root[i]=pole_s[i];

        pole_coeff_num=0;
        pole_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            pole_coeff_sum+=pole_root[j];
        }
        pole_coeff[pole_coeff_num]=pow(-1,pole_coeff_num+1)*pole_coeff_sum;

        pole_coeff_num=1;
        pole_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                pole_coeff_sum+=pole_root[j]*pole_root[k];
            }
        }
        pole_coeff[pole_coeff_num]=pow(-1,pole_coeff_num+1)*pole_coeff_sum;


        pole_coeff_num=2;
        pole_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    pole_coeff_sum+=pole_root[j]*pole_root[k]*pole_root[l];
                }
            }
        }
        pole_coeff[pole_coeff_num]=pow(-1,pole_coeff_num+1)*pole_coeff_sum;

        pole_coeff_num=3;
        pole_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    for(int m=l+1; m<APPROX_ORDER; m++){
                        pole_coeff_sum+=pole_root[j]*pole_root[k]*pole_root[l]*pole_root[m];
                    }
                }
            }
        }
        pole_coeff[pole_coeff_num]=pow(-1,pole_coeff_num+1)*pole_coeff_sum;

        pole_coeff_num=4;
        pole_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    for(int m=l+1; m<APPROX_ORDER; m++){
                        for(int n=m+1; n<APPROX_ORDER; n++){
                            pole_coeff_sum+=pole_root[j]*pole_root[k]*pole_root[l]*pole_root[m]*pole_root[n];
                        }
                    }
                }
            }
        }
        pole_coeff[pole_coeff_num]=pow(-1,pole_coeff_num+1)*pole_coeff_sum;

        pole_coeff_num=5;
        pole_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    for(int m=l+1; m<APPROX_ORDER; m++){
                        for(int n=m+1; n<APPROX_ORDER; n++){
                            for(int o=n+1; o<APPROX_ORDER; o++){
                                pole_coeff_sum+=pole_root[j]*pole_root[k]*pole_root[l]*pole_root[m]*pole_root[n]*pole_root[o];
                            }
                        }
                    }
                }
            }
        }
        pole_coeff[pole_coeff_num]=pow(-1,pole_coeff_num+1)*pole_coeff_sum;

        zero_coeff_num=0;
        zero_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            zero_coeff_sum+=zero_root[j];
        }
        zero_coeff[zero_coeff_num]=pow(-1,zero_coeff_num+1)*zero_coeff_sum;

        zero_coeff_num=1;
        zero_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                zero_coeff_sum+=zero_root[j]*zero_root[k];
            }
        }
        zero_coeff[zero_coeff_num]=pow(-1,zero_coeff_num+1)*zero_coeff_sum;


        zero_coeff_num=2;
        zero_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    zero_coeff_sum+=zero_root[j]*zero_root[k]*zero_root[l];
                }
            }
        }
        zero_coeff[zero_coeff_num]=pow(-1,zero_coeff_num+1)*zero_coeff_sum;

        zero_coeff_num=3;
        zero_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    for(int m=l+1; m<APPROX_ORDER; m++){
                        zero_coeff_sum+=zero_root[j]*zero_root[k]*zero_root[l]*zero_root[m];
                    }
                }
            }
        }
        zero_coeff[zero_coeff_num]=pow(-1,zero_coeff_num+1)*zero_coeff_sum;

        zero_coeff_num=4;
        zero_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    for(int m=l+1; m<APPROX_ORDER; m++){
                        for(int n=m+1; n<APPROX_ORDER; n++){
                            zero_coeff_sum+=zero_root[j]*zero_root[k]*zero_root[l]*zero_root[m]*zero_root[n];
                        }
                    }
                }
            }
        }
        zero_coeff[zero_coeff_num]=pow(-1,zero_coeff_num+1)*zero_coeff_sum;

        zero_coeff_num=5;
        zero_coeff_sum=0.0;
        for(int j=0; j<APPROX_ORDER; j++){
            for(int k=j+1; k<APPROX_ORDER; k++){
                for(int l=k+1; l<APPROX_ORDER; l++){
                    for(int m=l+1; m<APPROX_ORDER; m++){
                        for(int n=m+1; n<APPROX_ORDER; n++){
                            for(int o=n+1; o<APPROX_ORDER; o++){
                                zero_coeff_sum+=zero_root[j]*zero_root[k]*zero_root[l]*zero_root[m]*zero_root[n]*zero_root[o];
                            }
                        }
                    }
                }
            }
        }
        zero_coeff[zero_coeff_num]=pow(-1,zero_coeff_num+1)*zero_coeff_sum;

        pole_product_wn=1.0; zero_product_wn=1.0;
        if(pole_degree>0) for(int i=0;i<pole_degree;i++) pole_product_wn*=pole_s[i];
        if(zero_degree>0) for(int i=0;i<zero_degree;i++) zero_product_wn*=zero_s[i];
        Gs_gain_untuned=zero_product_wn.real()/pole_product_wn.real();

        Gs_gain_conv=Gs_gain_untuned/GZ_GAIN;
        for(int i=0;i<APPROX_ORDER;i++) pole_coeff[i]*=Gs_gain_conv;

        QString pole_ceq;
        pole_ceq=(pole_degree>=2)? QString::number(Gs_gain_conv)+QString("s^%1").arg(pole_degree):QString::number(Gs_gain_conv)+QString("s");
        for(int i=0;i<APPROX_ORDER;i++){
            if(abs(pole_coeff[i])>1e-3){
                if(!(pole_coeff[i].real()<0)) pole_ceq+="+";
                if(i==pole_degree-2) pole_ceq+=QString::number(pole_coeff[i].real())+QString("s");
                else if(i!=pole_degree-1) pole_ceq+=QString::number(pole_coeff[i].real())+QString("s^%1").arg(pole_degree-i-1);
                else pole_ceq+=QString::number(pole_coeff[i].real());
            }
        }
        if(pole_degree==0) pole_ceq="1";

        QString zero_ceq;
        zero_ceq=(zero_degree>=2)? QString("s^%1").arg(zero_degree):QString("s");
        for(int i=0;i<APPROX_ORDER;i++){
            if(abs(zero_coeff[i])>1e-3){
                if(!(zero_coeff[i].real()<0)) zero_ceq+="+";
                if(i==zero_degree-2) zero_ceq+=QString::number(zero_coeff[i].real())+QString("s");
                else if(i!=zero_degree-1) zero_ceq+=QString::number(zero_coeff[i].real())+QString("s^%1").arg(zero_degree-i-1);
                else zero_ceq+=QString::number(zero_coeff[i].real());
            }
        }
        if(zero_degree==0) zero_ceq="1";

        QString vinculum="--------------------------------";
        QString Gs=zero_ceq+"\n"+vinculum+"\n"+pole_ceq;
        ui->si_result_tfs->setText(Gs);
    }

    delete pole_a;
    delete pole_z;
    delete pole_s;
    delete pole_w;
    delete zero_a;
    delete zero_z;
    delete zero_s;
    delete pole_root;
    delete zero_root;
    delete pole_coeff;
    delete zero_coeff;

    emit(pz_getpz_fin());

}

/* Set table */
void MainWindow::set_timetable(){

    for(int lp1=0; lp1<DataT_Table_RowNUM; lp1++) {
        for(int lp2=0; lp2<DataT_Table_ColNUM; lp2++) {
            ui->table_data->setItem(lp1,lp2,new QTableWidgetItem(QString::number(Data[lp2][lp1],TABLE_FORMAT,TABLE_DIGIT)));
        }
    }

}

/* Open DATA */
void MainWindow::open_data(){

    //INPUT FILE NAME
    QString Path_Desktop = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString file_title = tr("Open File");
    QString file_filter = tr("DAT (*.dat);;All Files (*)");
    QString file_subfilter = tr("DAT (*.dat)");
    QFlag file_option = QFileDialog::DontUseCustomDirectoryIcons;
    QString fileName = QFileDialog::getOpenFileName(this, file_title,Path_Desktop, file_filter,&file_subfilter,file_option);
    if(fileName.isEmpty()) return;

    QFile file(fileName);
    QFileInfo fileinfo(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    ui->data_path->setText(fileinfo.absoluteFilePath());

    QTextStream in(&file);
    QString line;
    QString linesplitter;
    linesplitter = (ui->input_separator_tab->isChecked())? "\t": (ui->input_separator_comma->isChecked())? ",":" ";

    //Reset NumOfData along changing dataset.
    DataT_ColNUM = 0;
    DataT_RowNUM = 0;

    line = in.readLine();
    for(QString item: line.split(linesplitter)){ DataT_ColNUM++; }
    in.seek(0);

    while ( !in.atEnd() ){ line = in.readLine(); DataT_RowNUM++; }
    in.seek(0);

    //Release secured area (if any) and re-secure new area
    delete[] Data[0];
    delete[] Data;
    Data = new double* [DataT_ColNUM];
    Data[0] = new double[DataT_RowNUM*DataT_ColNUM];
    for(int n=1;n<DataT_ColNUM;n++) Data[n]=Data[0]+n*DataT_RowNUM;

    //Make the framework of the table
    DataT_Table_RowNUM = (DataT_RowNUM>DataT_ROW_MAX)? DataT_ROW_MAX:DataT_RowNUM;
    DataT_Table_ColNUM = (DataT_ColNUM>DataT_COL_MAX)? DataT_COL_MAX:DataT_ColNUM;
    ui->table_data->clear();
    ui->table_data->setRowCount(DataT_Table_RowNUM);
    ui->table_data->setColumnCount(DataT_Table_ColNUM);

    //Make the dataset
    for(int lp=0; lp<DataT_RowNUM; lp++) {
        line = in.readLine();
        ColumnCnt=0;
        for(QString item: line.split(linesplitter)) {
            Data[ColumnCnt][lp] = item.toDouble();
            ColumnCnt++;
        }
    }
    in.seek(0);

    int get_ts_cnt=0;
    double get_ts_buf_u0=0.0;
    double get_ts_buf_u1=0.0;
    double get_ts=0.0;
    double get_ts_def=0.0;
    QString get_ts_set="\0";
    for(int lp=1; lp<DataT_RowNUM; lp++){
        get_ts_cnt++;
        get_ts_buf_u0=Data[0][lp]-Data[0][lp-1];
        if((get_ts_buf_u0-get_ts_buf_u1)>1e-9){ get_ts=get_ts_buf_u0; get_ts_cnt=0; }
        if(get_ts_cnt==100){ lp=DataT_RowNUM; get_ts_def=get_ts; }
        get_ts_buf_u1=get_ts_buf_u0;
    }
    if(get_ts_def==0.0) get_ts_def=1e-4;
    get_ts_set=QString::number(get_ts_def,TS_FORMAT,TS_DIGIT);
    ui->si_ts->setText(get_ts_set);
    ui->fft_ts->setText(get_ts_set);
    ui->time_ts->setText(get_ts_set);

    file.close();
    emit(load_data_fin());

}


/* Load DATA */
void MainWindow::load_data(){

    QString DataPath;
    DataPath = ui->data_path->text();

    QFile file(DataPath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }

    QTextStream in(&file);
    QString line;
    QString linesplitter;
    linesplitter = (ui->input_separator_tab->isChecked())? "\t": (ui->input_separator_comma->isChecked())? ",":" ";

    //Reset NumOfData along changing dataset.
    DataT_ColNUM = 0;
    DataT_RowNUM = 0;

    line = in.readLine();
    for(QString item: line.split(linesplitter)){ DataT_ColNUM++; }
    in.seek(0);

    while ( !in.atEnd() ){ line = in.readLine(); DataT_RowNUM++; }
    in.seek(0);

    //Release secured area (if any) and re-secure new area
    delete[] Data[0];
    delete[] Data;
    Data = new double* [DataT_ColNUM];
    Data[0] = new double[DataT_RowNUM*DataT_ColNUM];
    for(int n=1;n<DataT_ColNUM;n++) Data[n]=Data[0]+n*DataT_RowNUM;

    //Make the framework of the table
    DataT_Table_RowNUM = (DataT_RowNUM>DataT_ROW_MAX)? DataT_ROW_MAX:DataT_RowNUM;
    DataT_Table_ColNUM = (DataT_ColNUM>DataT_COL_MAX)? DataT_COL_MAX:DataT_ColNUM;
    ui->table_data->clear();
    ui->table_data->setRowCount(DataT_Table_RowNUM);
    ui->table_data->setColumnCount(DataT_Table_ColNUM);

    //Make the dataset
    for(int lp=0; lp<DataT_RowNUM; lp++){
        line = in.readLine();
        ColumnCnt=0;
        for(QString item: line.split(linesplitter)) {
            Data[ColumnCnt][lp] = item.toDouble();
            ColumnCnt++;
        }
    }
    in.seek(0);

    int get_ts_cnt=0;
    double get_ts_buf_u0=0.0;
    double get_ts_buf_u1=0.0;
    double get_ts=0.0;
    QString get_ts_set="\0";
    for(int lp=1; lp<DataT_RowNUM; lp++){
        get_ts_cnt++;
        get_ts_buf_u0=Data[0][lp]-Data[0][lp-1];
        if((get_ts_buf_u0-get_ts_buf_u1)>1e-9){ get_ts=get_ts_buf_u0; get_ts_cnt=0; }
        if(get_ts_cnt==GET_TS_CNTWIDTH){ lp=DataT_RowNUM; get_ts_set=QString::number(get_ts,TS_FORMAT,TS_DIGIT); }
        get_ts_buf_u1=get_ts_buf_u0;
    }
    ui->fft_ts->setText(get_ts_set);
    ui->si_ts->setText(get_ts_set);
    ui->time_ts->setText(get_ts_set);

    file.close();
    emit(load_data_fin());

}


/* Save DATA */
void MainWindow::save_data(){

    //INPUT FILE NAME
    QString Path_Desktop = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString save_title = tr("Save Data");
    QString save_filter = tr("DAT (*.dat);;All Files (*)");
    QString save_subfilter = tr("DAT (*.dat)");
    QFlag save_option = QFileDialog::DontUseCustomDirectoryIcons;
    QString SaveFileName = QFileDialog::getSaveFileName(this, save_title,Path_Desktop, save_filter,&save_subfilter,save_option);
    if(SaveFileName.isEmpty()) return;

    //GENERATE DATA.
    vector<double> lx,ly,lz;
    const double Ts=1e-4;
    unsigned long lsize=60000;
    lx.resize(lsize);
    ly.resize(lsize);
    lz.resize(lsize);
    for(unsigned short i=0;i<lsize;i++){
        double vx=Ts*i;
        double vy=1.0*sin(2.0*M_PI*10.0*vx);
        double vz=1.0*cos(2.0*M_PI*15.0*vx);
        lx[i]=vx;
        ly[i]=vy;
        lz[i]=vz;
    }
    //CONVERT TO STRING.
    stringstream ss;
    for(unsigned short i=0;i<lsize;i++){
        ss << lx[i] << "\t" << ly[i] << "\t" << lz[i] << endl;
    }

    //WRITE TO FILE.
    QFile file(SaveFileName);

    if (!file.open(QIODevice::WriteOnly)){
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QTextStream out(&file);
    out << ss.str().c_str();

    file.close();
}
