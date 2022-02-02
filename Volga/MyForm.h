#pragma once
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include <msclr\marshal_windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio> 
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


namespace Volga {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace std;
using namespace System::Threading;
using namespace System::Threading::Tasks;

double **dotsT;		// массив значений точек траектории
double **planT;		// массив значений точек плана траектории
double **horiz;		// массив значений точек горизонтов (x1-z1, x2-z2)

int nD = 3;		// кол-во координат точек траектории
int nP = 3;		// кол-во координат точек плана траектории
int nH = 4;		// кол-во координат точек горизонтов

int N;		// количество точек траектории (2 ≤ N ≤ 100)
int M;		// количество точек плана (2 ≤ M ≤ 100)
int K;		// количество точек горизонтов (0 ≤ K ≤ 10)

double maxDev;		// допустимое отклонение

double *xDotsOld;
double *yDotsOld;
double *zDotsOld;
double *xPlanOld;
double *yPlanOld;
double *zPlanOld;

double *massC = new double[3];
double *massMinMax = new double[6];


/// <summary>
/// Сводка для MyForm
/// </summary>
public ref class MyForm : public System::Windows::Forms::Form
{
public:
	MyForm(void)
	{
		InitializeComponent();
		//
		//TODO: добавьте код конструктора
		//
	}

protected:
	/// <summary>
	/// Освободить все используемые ресурсы.
	/// </summary>
	~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}

protected:

protected:

private: System::Windows::Forms::Button^  loadFile;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog;

private: System::Windows::Forms::TextBox^  infoBox;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Button^  buttonChart;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartUp;

private: System::Windows::Forms::Label^  label1;


private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartSide;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TabControl^  tabControl;

private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::TabPage^  tabPage1;


private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
private: System::Windows::Forms::NumericUpDown^  numericUpDownX;
private: System::Windows::Forms::NumericUpDown^  numericUpDownY;
private: System::Windows::Forms::NumericUpDown^  numericUpDownZ;



private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Button^  buttonMplus;
private: System::Windows::Forms::Button^  buttonMminus;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Label^  label6;











private: System::ComponentModel::IContainer^  components;


protected:

private:
	/// <summary>
	/// Обязательная переменная конструктора.
	/// </summary>


#pragma region Windows Form Designer generated code
	/// <summary>
	/// Требуемый метод для поддержки конструктора — не изменяйте 
	/// содержимое этого метода с помощью редактора кода.
	/// </summary>
	void InitializeComponent(void)
	{
		System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
		System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
		System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
		System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		this->loadFile = (gcnew System::Windows::Forms::Button());
		this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
		this->infoBox = (gcnew System::Windows::Forms::TextBox());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->buttonChart = (gcnew System::Windows::Forms::Button());
		this->chartUp = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->chartSide = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->tabControl = (gcnew System::Windows::Forms::TabControl());
		this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		this->buttonMplus = (gcnew System::Windows::Forms::Button());
		this->buttonMminus = (gcnew System::Windows::Forms::Button());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->numericUpDownX = (gcnew System::Windows::Forms::NumericUpDown());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->numericUpDownY = (gcnew System::Windows::Forms::NumericUpDown());
		this->numericUpDownZ = (gcnew System::Windows::Forms::NumericUpDown());
		this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
		this->panel1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartUp))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartSide))->BeginInit();
		this->tabControl->SuspendLayout();
		this->tabPage1->SuspendLayout();
		this->tabPage2->SuspendLayout();
		this->groupBox2->SuspendLayout();
		this->groupBox1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
		this->SuspendLayout();
		// 
		// loadFile
		// 
		this->loadFile->Location = System::Drawing::Point(7, 8);
		this->loadFile->Name = L"loadFile";
		this->loadFile->Size = System::Drawing::Size(220, 28);
		this->loadFile->TabIndex = 1;
		this->loadFile->Text = L"Загрузить файл с данными";
		this->loadFile->UseVisualStyleBackColor = true;
		this->loadFile->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		// 
		// openFileDialog
		// 
		this->openFileDialog->FileName = L"openFileDialog1";
		// 
		// infoBox
		// 
		this->infoBox->Cursor = System::Windows::Forms::Cursors::No;
		this->infoBox->Location = System::Drawing::Point(11, 609);
		this->infoBox->Multiline = true;
		this->infoBox->Name = L"infoBox";
		this->infoBox->ReadOnly = true;
		this->infoBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
		this->infoBox->Size = System::Drawing::Size(1233, 31);
		this->infoBox->TabIndex = 2;
		// 
		// panel1
		// 
		this->panel1->Controls->Add(this->button1);
		this->panel1->Controls->Add(this->loadFile);
		this->panel1->Controls->Add(this->buttonChart);
		this->panel1->Location = System::Drawing::Point(1022, 40);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(232, 518);
		this->panel1->TabIndex = 3;
		// 
		// button1
		// 
		this->button1->Enabled = false;
		this->button1->Location = System::Drawing::Point(7, 101);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(220, 46);
		this->button1->TabIndex = 4;
		this->button1->Text = L"Динамическое построение траектории";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
		// 
		// buttonChart
		// 
		this->buttonChart->Enabled = false;
		this->buttonChart->Location = System::Drawing::Point(7, 41);
		this->buttonChart->Name = L"buttonChart";
		this->buttonChart->Size = System::Drawing::Size(220, 28);
		this->buttonChart->TabIndex = 3;
		this->buttonChart->Text = L"Построить графики";
		this->buttonChart->UseVisualStyleBackColor = true;
		this->buttonChart->Click += gcnew System::EventHandler(this, &MyForm::buttonChart_Click);
		// 
		// chartUp
		// 
		this->chartUp->BackColor = System::Drawing::Color::Gainsboro;
		this->chartUp->BorderlineColor = System::Drawing::Color::DimGray;
		this->chartUp->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
		chartArea1->AxisX->LabelAutoFitMaxFontSize = 8;
		chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::Silver;
		chartArea1->AxisX->ScaleBreakStyle->Spacing = 10;
		chartArea1->AxisX->Title = L"X";
		chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		chartArea1->AxisY->LabelAutoFitMaxFontSize = 8;
		chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::Silver;
		chartArea1->AxisY->Title = L"Y";
		chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		chartArea1->BackColor = System::Drawing::Color::WhiteSmoke;
		chartArea1->Name = L"ChartArea1";
		this->chartUp->ChartAreas->Add(chartArea1);
		legend1->Name = L"Legend1";
		this->chartUp->Legends->Add(legend1);
		this->chartUp->Location = System::Drawing::Point(3, 33);
		this->chartUp->Name = L"chartUp";
		series1->BorderWidth = 3;
		series1->ChartArea = L"ChartArea1";
		series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		series1->IsVisibleInLegend = false;
		series1->Legend = L"Legend1";
		series1->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		series1->MarkerSize = 8;
		series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		series1->Name = L"SeriesPlan";
		series2->BackSecondaryColor = System::Drawing::Color::Transparent;
		series2->BorderColor = System::Drawing::Color::Transparent;
		series2->BorderWidth = 3;
		series2->ChartArea = L"ChartArea1";
		series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series2->Color = System::Drawing::Color::Black;
		series2->IsVisibleInLegend = false;
		series2->Legend = L"Legend1";
		series2->MarkerColor = System::Drawing::Color::Black;
		series2->MarkerSize = 8;
		series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		series2->Name = L"SeriesDots";
		this->chartUp->Series->Add(series1);
		this->chartUp->Series->Add(series2);
		this->chartUp->Size = System::Drawing::Size(496, 518);
		this->chartUp->TabIndex = 4;
		this->chartUp->Text = L"Вид сверху";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label1->Location = System::Drawing::Point(-1, 6);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(112, 24);
		this->label1->TabIndex = 5;
		this->label1->Text = L"Вид сверху";
		// 
		// chartSide
		// 
		this->chartSide->BackColor = System::Drawing::Color::Gainsboro;
		this->chartSide->BorderlineColor = System::Drawing::Color::DimGray;
		this->chartSide->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
		chartArea2->AxisX->LabelAutoFitMaxFontSize = 8;
		chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::Silver;
		chartArea2->AxisX->ScaleBreakStyle->Spacing = 10;
		chartArea2->AxisX->Title = L"X";
		chartArea2->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		chartArea2->AxisY->LabelAutoFitMaxFontSize = 8;
		chartArea2->AxisY->MajorGrid->LineColor = System::Drawing::Color::Silver;
		chartArea2->AxisY->Title = L"Z";
		chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		chartArea2->BackColor = System::Drawing::Color::WhiteSmoke;
		chartArea2->Name = L"ChartArea1";
		this->chartSide->ChartAreas->Add(chartArea2);
		legend2->Name = L"Legend1";
		this->chartSide->Legends->Add(legend2);
		this->chartSide->Location = System::Drawing::Point(503, 33);
		this->chartSide->Name = L"chartSide";
		series3->BorderWidth = 3;
		series3->ChartArea = L"ChartArea1";
		series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		series3->IsVisibleInLegend = false;
		series3->Legend = L"Legend1";
		series3->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		series3->MarkerSize = 8;
		series3->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		series3->Name = L"SeriesPlan";
		series4->BackSecondaryColor = System::Drawing::Color::Transparent;
		series4->BorderColor = System::Drawing::Color::Transparent;
		series4->BorderWidth = 3;
		series4->ChartArea = L"ChartArea1";
		series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series4->Color = System::Drawing::Color::Black;
		series4->IsVisibleInLegend = false;
		series4->Legend = L"Legend1";
		series4->MarkerColor = System::Drawing::Color::Black;
		series4->MarkerSize = 8;
		series4->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		series4->Name = L"SeriesDots";
		this->chartSide->Series->Add(series3);
		this->chartSide->Series->Add(series4);
		this->chartSide->Size = System::Drawing::Size(496, 518);
		this->chartSide->TabIndex = 7;
		this->chartSide->Text = L"Вид сверху";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label2->Location = System::Drawing::Point(499, 6);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(100, 24);
		this->label2->TabIndex = 8;
		this->label2->Text = L"Вид сбоку";
		// 
		// tabControl
		// 
		this->tabControl->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
		this->tabControl->Controls->Add(this->tabPage1);
		this->tabControl->Controls->Add(this->tabPage2);
		this->tabControl->Location = System::Drawing::Point(7, 12);
		this->tabControl->Name = L"tabControl";
		this->tabControl->SelectedIndex = 0;
		this->tabControl->Size = System::Drawing::Size(1022, 596);
		this->tabControl->TabIndex = 9;
		// 
		// tabPage1
		// 
		this->tabPage1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->tabPage1->Controls->Add(this->chartUp);
		this->tabPage1->Controls->Add(this->label2);
		this->tabPage1->Controls->Add(this->label1);
		this->tabPage1->Controls->Add(this->chartSide);
		this->tabPage1->Location = System::Drawing::Point(4, 28);
		this->tabPage1->Name = L"tabPage1";
		this->tabPage1->Padding = System::Windows::Forms::Padding(3);
		this->tabPage1->Size = System::Drawing::Size(1014, 564);
		this->tabPage1->TabIndex = 0;
		this->tabPage1->Text = L"2D-отображение";
		this->tabPage1->UseVisualStyleBackColor = true;
		// 
		// tabPage2
		// 
		this->tabPage2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->tabPage2->Controls->Add(this->label6);
		this->tabPage2->Controls->Add(this->groupBox2);
		this->tabPage2->Controls->Add(this->groupBox1);
		this->tabPage2->Controls->Add(this->chart1);
		this->tabPage2->Location = System::Drawing::Point(4, 28);
		this->tabPage2->Name = L"tabPage2";
		this->tabPage2->Padding = System::Windows::Forms::Padding(3);
		this->tabPage2->Size = System::Drawing::Size(1014, 564);
		this->tabPage2->TabIndex = 1;
		this->tabPage2->Text = L"3D-отображение*";
		this->tabPage2->UseVisualStyleBackColor = true;
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label6->Location = System::Drawing::Point(784, 532);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(132, 17);
		this->label6->TabIndex = 18;
		this->label6->Text = L"*проекция на (X,Z)";
		// 
		// groupBox2
		// 
		this->groupBox2->Controls->Add(this->buttonMplus);
		this->groupBox2->Controls->Add(this->buttonMminus);
		this->groupBox2->Location = System::Drawing::Point(788, 148);
		this->groupBox2->Name = L"groupBox2";
		this->groupBox2->Size = System::Drawing::Size(200, 79);
		this->groupBox2->TabIndex = 17;
		this->groupBox2->TabStop = false;
		this->groupBox2->Text = L"Масштаб";
		// 
		// buttonMplus
		// 
		this->buttonMplus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->buttonMplus->Location = System::Drawing::Point(41, 31);
		this->buttonMplus->Name = L"buttonMplus";
		this->buttonMplus->Size = System::Drawing::Size(39, 28);
		this->buttonMplus->TabIndex = 15;
		this->buttonMplus->Text = L"+";
		this->buttonMplus->UseVisualStyleBackColor = true;
		this->buttonMplus->Click += gcnew System::EventHandler(this, &MyForm::buttonMplus_Click);
		// 
		// buttonMminus
		// 
		this->buttonMminus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->buttonMminus->Location = System::Drawing::Point(113, 31);
		this->buttonMminus->Name = L"buttonMminus";
		this->buttonMminus->Size = System::Drawing::Size(39, 28);
		this->buttonMminus->TabIndex = 16;
		this->buttonMminus->Text = L"-";
		this->buttonMminus->UseVisualStyleBackColor = true;
		this->buttonMminus->Click += gcnew System::EventHandler(this, &MyForm::buttonMminus_Click);
		// 
		// groupBox1
		// 
		this->groupBox1->Controls->Add(this->label5);
		this->groupBox1->Controls->Add(this->label4);
		this->groupBox1->Controls->Add(this->numericUpDownX);
		this->groupBox1->Controls->Add(this->label3);
		this->groupBox1->Controls->Add(this->numericUpDownY);
		this->groupBox1->Controls->Add(this->numericUpDownZ);
		this->groupBox1->Location = System::Drawing::Point(788, 6);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Size = System::Drawing::Size(200, 136);
		this->groupBox1->TabIndex = 14;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"Угол поворота";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label5->Location = System::Drawing::Point(16, 97);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(64, 17);
		this->label5->TabIndex = 15;
		this->label5->Text = L"по оси Z";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label4->Location = System::Drawing::Point(16, 67);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(64, 17);
		this->label4->TabIndex = 14;
		this->label4->Text = L"по оси Y";
		// 
		// numericUpDownX
		// 
		this->numericUpDownX->Location = System::Drawing::Point(95, 34);
		this->numericUpDownX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
		this->numericUpDownX->Name = L"numericUpDownX";
		this->numericUpDownX->Size = System::Drawing::Size(74, 22);
		this->numericUpDownX->TabIndex = 10;
		this->numericUpDownX->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownX_ValueChanged);
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label3->Location = System::Drawing::Point(16, 36);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(64, 17);
		this->label3->TabIndex = 13;
		this->label3->Text = L"по оси X";
		// 
		// numericUpDownY
		// 
		this->numericUpDownY->Location = System::Drawing::Point(95, 65);
		this->numericUpDownY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
		this->numericUpDownY->Name = L"numericUpDownY";
		this->numericUpDownY->Size = System::Drawing::Size(74, 22);
		this->numericUpDownY->TabIndex = 12;
		this->numericUpDownY->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownY_ValueChanged);
		// 
		// numericUpDownZ
		// 
		this->numericUpDownZ->Location = System::Drawing::Point(95, 95);
		this->numericUpDownZ->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
		this->numericUpDownZ->Name = L"numericUpDownZ";
		this->numericUpDownZ->Size = System::Drawing::Size(74, 22);
		this->numericUpDownZ->TabIndex = 11;
		this->numericUpDownZ->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownZ_ValueChanged);
		// 
		// chart1
		// 
		this->chart1->BackColor = System::Drawing::Color::Gainsboro;
		this->chart1->BorderlineColor = System::Drawing::Color::DimGray;
		this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
		chartArea3->AxisX->Crossing = 1.7976931348623157E+308;
		chartArea3->AxisX->LabelAutoFitMaxFontSize = 8;
		chartArea3->AxisX->LabelStyle->Enabled = false;
		chartArea3->AxisX->LineColor = System::Drawing::Color::Transparent;
		chartArea3->AxisX->MajorGrid->Enabled = false;
		chartArea3->AxisX->MajorGrid->LineColor = System::Drawing::Color::Silver;
		chartArea3->AxisX->MajorTickMark->Enabled = false;
		chartArea3->AxisX->ScaleBreakStyle->Spacing = 10;
		chartArea3->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		chartArea3->AxisY->LabelAutoFitMaxFontSize = 8;
		chartArea3->AxisY->LabelStyle->Enabled = false;
		chartArea3->AxisY->LineColor = System::Drawing::Color::Transparent;
		chartArea3->AxisY->MajorGrid->Enabled = false;
		chartArea3->AxisY->MajorGrid->LineColor = System::Drawing::Color::Silver;
		chartArea3->AxisY->MajorTickMark->Enabled = false;
		chartArea3->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		chartArea3->BackColor = System::Drawing::Color::WhiteSmoke;
		chartArea3->BorderWidth = 0;
		chartArea3->Name = L"ChartArea1";
		this->chart1->ChartAreas->Add(chartArea3);
		legend3->Name = L"Legend1";
		this->chart1->Legends->Add(legend3);
		this->chart1->Location = System::Drawing::Point(6, 6);
		this->chart1->Name = L"chart1";
		series5->BorderWidth = 3;
		series5->ChartArea = L"ChartArea1";
		series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		series5->IsVisibleInLegend = false;
		series5->Legend = L"Legend1";
		series5->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		series5->MarkerSize = 8;
		series5->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		series5->Name = L"SeriesPlan";
		series6->BackSecondaryColor = System::Drawing::Color::Transparent;
		series6->BorderColor = System::Drawing::Color::Transparent;
		series6->BorderWidth = 3;
		series6->ChartArea = L"ChartArea1";
		series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		series6->Color = System::Drawing::Color::Black;
		series6->IsVisibleInLegend = false;
		series6->Legend = L"Legend1";
		series6->MarkerColor = System::Drawing::Color::Black;
		series6->MarkerSize = 8;
		series6->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
		series6->Name = L"SeriesDots";
		this->chart1->Series->Add(series5);
		this->chart1->Series->Add(series6);
		this->chart1->Size = System::Drawing::Size(772, 546);
		this->chart1->TabIndex = 8;
		this->chart1->Text = L"Вид сверху";
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1252, 643);
		this->Controls->Add(this->infoBox);
		this->Controls->Add(this->tabControl);
		this->Controls->Add(this->panel1);
		this->MaximumSize = System::Drawing::Size(1270, 690);
		this->MinimumSize = System::Drawing::Size(1270, 690);
		this->Name = L"MyForm";
		this->Text = L"Volga Drilling";
		this->panel1->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartUp))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartSide))->EndInit();
		this->tabControl->ResumeLayout(false);
		this->tabPage1->ResumeLayout(false);
		this->tabPage1->PerformLayout();
		this->tabPage2->ResumeLayout(false);
		this->tabPage2->PerformLayout();
		this->groupBox2->ResumeLayout(false);
		this->groupBox1->ResumeLayout(false);
		this->groupBox1->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownX))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownY))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownZ))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие при нажатии кнопки "Загрузить файл с данными"
	//

	// диалоговое окно выбора файла
	openFileDialog->ShowDialog();	
	try {
		openFileDialog->OpenFile();
	}
	// обработка возникающих при открытии файла исключений
	catch (...) {
		infoBox->Text = "Ошибка при открытии файла";
	}

	// получение пути к файлу в виде строки
	string str = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);	
	const char * way = str.c_str();		

	// открытие файла на чтение
	ifstream file;
	file.open(way, ios::in);

	infoBox->Text = "";
	if (file)
	{
		file >> N >> M >> K;

		if (N < 2 || N > 100) infoBox->Text += "Количество точек траектории должно находиться в интервале [2, 100]\n";
		else if (M < 2 || M > 100) infoBox->Text += "Количество точек плана траектории должно находиться в интервале [2, 100]\n";
		else if (K > 10) infoBox->Text += "Количество точек горизонта должно находиться в интервале [0, 10]\n";
		else
		{
			file >> maxDev;

			// выделение памяти под массивы и заполнение значениями из файла
			dotsT = new double*[N];
			planT = new double*[M];
			for (int i = 0; i < N; i++) {
				dotsT[i] = new double[nD];
				for (int j = 0; j < nD; j++)
				{
					file >> dotsT[i][j];
					if (j == 2)
						dotsT[i][j] = -dotsT[i][j];		// минус, т.к. ось Z отражает глубину
				}
					
			}
			for (int i = 0; i < M; i++) {
				planT[i] = new double[nP];
				for (int j = 0; j < nP; j++)
				{
					file >> planT[i][j];
					if (j == 2)
						planT[i][j] = -planT[i][j];
				}
			}

			if (K > 0)		// проверяем, присутствуют ли горизонты
			{
				horiz = new double*[K];
				for (int i = 0; i < K; i++) {
					horiz[i] = new double[nH];
					for (int j = 0; j < nH; j++)
					{
						file >> horiz[i][j];
						if (j == 1 || j == 3)
							horiz[i][j] = -horiz[i][j];
					}
				}
			}

			file.close();

			// после загрузки данных можно строить графики
			buttonChart->Enabled = true;
			button1->Enabled = true;
		}
	}
	else infoBox->Text = "Ошибка при чтении файла";
	
}
private: System::Void buttonChart_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие при нажатии кнопки "Построить графики"
	//
		
	chartUp->Series["SeriesDots"]->Points->Clear();
	chartSide->Series["SeriesDots"]->Points->Clear();
	chartUp->Series["SeriesPlan"]->Points->Clear();
	chartSide->Series["SeriesPlan"]->Points->Clear();
	chart1->Series[0]->Points->Clear();
	chart1->Series[1]->Points->Clear();

	double minX, maxX = dotsT[0][0]; double minY, maxY = dotsT[0][1]; double minZ, maxZ = dotsT[0][2];

	for (int i = 0; i < M; i++)
	{
		// вывод точек плана траектории на 2д-графики
		chartUp->Series["SeriesPlan"]->Points->AddXY(planT[i][0], planT[i][1]);
		chartSide->Series["SeriesPlan"]->Points->AddXY(planT[i][0], planT[i][2]);

		// поиск минимальной и максимальной точки для каждой оси для отрисовки графика
		if (planT[i][0] < minX) minX = planT[i][0];
		else if (planT[i][0] > maxX) maxX = planT[i][0];

		if (planT[i][1] < minY) minY = planT[i][1];
		else if (planT[i][1] > maxY) maxY = planT[i][1];

		if (planT[i][2] < minZ) minZ = planT[i][2];
		else if (planT[i][2] > maxZ) maxZ = planT[i][2];

		// вывод точек на 3д-график
		chart1->Series[0]->Points->AddXY(planT[i][0], planT[i][2]);
	}

	for (int i = 0; i < N; i++)
	{
		// вывод точек траектории на 2д-графики
		chartUp->Series["SeriesDots"]->Points->AddXY(dotsT[i][0], dotsT[i][1]);
		chartSide->Series["SeriesDots"]->Points->AddXY(dotsT[i][0], dotsT[i][2]);

		if (dotsT[i][0] < minX) minX = dotsT[i][0];
		else if (dotsT[i][0] > maxX) maxX = dotsT[i][0];

		if (dotsT[i][1] < minY) minY = dotsT[i][1];
		else if (dotsT[i][1] > maxY) maxY = dotsT[i][1];

		if (dotsT[i][2] < minZ) minZ = dotsT[i][2];
		else if (dotsT[i][2] > maxZ) maxZ = dotsT[i][2];

		// вывод точек на 3д-график
		chart1->Series[1]->Points->AddXY(dotsT[i][0], dotsT[i][2]);
	}

	// рисуем горизонты (если они есть) и тревожные отрезки
	if (horiz)
	{
		float pX, pZ;	// координаты точки пересечения, если пересечение есть

		for (int i = 0; i < N-1; i++)
		{
			double aX1 = dotsT[i][0];
			double aZ1 = dotsT[i][2];
			double aX2 = dotsT[i+1][0];
			double aZ2 = dotsT[i+1][2];

			for (int j = 0; j < K; j++)
			{
				double bX1 = horiz[j][0];
				double bZ1 = horiz[j][1];
				double bX2 = horiz[j][2];
				double bZ2 = horiz[j][3];

				if ((aX1 - aX2)*(bZ1 - bZ2) - (aZ1 - aZ2)*(bX1 - bX2) != 0)
				{
					// сортируем точки по возрастанию (для проверки условия)
					if (bX1 > bX2) {
						bX2 = bX1;
						bX1 = horiz[j][2];
					}
					if (bZ1 > bZ2) {
						bZ2 = bZ1;
						bZ1 = horiz[j][3];
					}
					if (aX1 > aX2) {
						aX2 = aX1;
						aX1 = dotsT[i+1][0];
					}
					if (aZ1 > aZ2) {
						aZ2 = aZ1;
						aZ1 = dotsT[i+1][2];
					}
					// вычисляем координаты точки пересечения двух прямых
					pX = ((aX1*aZ2 - aZ1 * aX2) * (bX1 - bX2) - (aX1 - aX2) * (bX1*bZ2 - bZ1 * bX2)) / ((aX1 - aX2)*(bZ1 - bZ2) - (aZ1 - aZ2)*(bX1 - bX2));
					pZ = ((aX1*aZ2 - aZ1 * aX2) * (bZ1 - bZ2) - (aZ1 - aZ2) * (bX1*bZ2 - bZ1 * bX2)) / ((aX1 - aX2)*(bZ1 - bZ2) - (aZ1 - aZ2)*(bX1 - bX2));

					// проверяем, лежит ли точка пересечения на отрезках
					if (pX >= aX1 && pX <= aX2 && 
						pX >= bX1 && pX <= bX2 && 
						pZ >= aZ1 && pZ <= aZ2 && 
						pZ >= bZ1 && pZ <= bZ2) {
						// выделяем тревожный отрезок красным цветом
						chartSide->Series["SeriesDots"]->Points[i]->MarkerColor = Color::Red;
						chartSide->Series["SeriesDots"]->Points[i+1]->Color = Color::Red;
						chartSide->Series["SeriesDots"]->Points[i+1]->MarkerColor = Color::Red;
					}
				}
				continue;
			}
		}

		for (int i = 0; i < K; i++)
		{
			// вывод точек горизонта на 2д-график и настройка их отображения
			chartSide->Series->Add("");
			chartSide->Series[i+2]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chartSide->Series[i+2]->MarkerSize = 8;
			chartSide->Series[i+2]->BorderWidth = 3;
			chartSide->Series[i+2]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			chartSide->Series[i+2]->Color = Color::Green;
			chartSide->Series[i+2]->MarkerColor = Color::Green;
			chartSide->Legends["Legend1"]->Enabled = false;
			chartSide->Series[i+2]->Points->AddXY(horiz[i][0], horiz[i][1]);
			chartSide->Series[i+2]->Points->AddXY(horiz[i][2], horiz[i][3]);

			// поиск минимальной и максимальной точки для каждой оси для отрисовки графика
			if (horiz[i][0] < minX) minX = horiz[i][0];
			else if (horiz[i][0] > maxX) maxX = horiz[i][0];
			if (horiz[i][2] < minX) minX = horiz[i][2];
			else if (horiz[i][2] > maxX) maxX = horiz[i][2];

			if (horiz[i][1] < minZ) minZ = horiz[i][1];
			else if (horiz[i][1] > maxZ) maxZ = horiz[i][1];
			if (horiz[i][3] < minZ) minZ = horiz[i][3];
			else if (horiz[i][3] > maxZ) maxZ = horiz[i][3];
		}

	}

	// делаем отступы от осей для 2д-графиков и приятный интервал между делениями оси Х
	double s = abs((minX - maxX) / 10);		
	chartUp->ChartAreas[0]->AxisX->Minimum = floor(minX - s);
	chartUp->ChartAreas[0]->AxisX->Maximum = ceil(maxX + s);
	chartSide->ChartAreas[0]->AxisX->Minimum = floor(minX - s);
	chartSide->ChartAreas[0]->AxisX->Maximum = ceil(maxX + s);

	s = abs((minY - maxY) / 10);
	chartUp->ChartAreas[0]->AxisY->Minimum = floor(minY - s);
	chartUp->ChartAreas[0]->AxisY->Maximum = ceil(maxY + s);
	chartUp->ChartAreas[0]->AxisX->Interval = round((ceil(maxX + s) - floor(minX - s)) / 7);	// 7 делений на оси
	
	s = abs((minZ - maxZ) / 10);
	chartSide->ChartAreas[0]->AxisY->Minimum = floor(minZ - s);
	chartSide->ChartAreas[0]->AxisY->Maximum = ceil(maxZ + s);
	chartSide->ChartAreas[0]->AxisX->Interval = round((ceil(maxX + s) - floor(minX - s)) / 7);	


	double vecX, vecY, vecZ;	// координаты направляющего вектора
	double pX, pY, pZ;			// координаты точки перпендикуляра
	double dist;

	// поиск тревожных точек
	int j = 0;
	for (int i = 0; i < N; i++)
	{
	A:
		// находим координаты направляющего вектора плана траектории
		vecX = planT[j + 1][0] - planT[j][0];
		vecY = planT[j + 1][1] - planT[j][1];
		vecZ = planT[j + 1][2] - planT[j][2];

		// Пусть точка А - точка траектории, отрезок BC - план траектории. Тогда расстояние между А и ВС можно представить как перпендикуляр в точке М.
		// Составим систему ур-й: параметрическое уравнение прямой М=B+(C-B)t, при этом АМ перпендикулярен ВС, тогда скалярное произведение (АМ,ВС)=0
		// Из системы ур-й выражаем t
		double t = (vecX * (dotsT[i][0] - planT[j][0]) + vecY * (dotsT[i][1] - planT[j][1]) + vecZ * (dotsT[i][2] - planT[j][2])) /
			(pow(vecX, 2) + pow(vecY, 2) + pow(vecZ, 2));

		// координаты точки пересечения перпендикуляра и прямой
		pX = planT[j][0] + vecX * t;
		pY = planT[j][1] + vecY * t;
		pZ = planT[j][2] + vecZ * t;

		// при 0<t<1 получаем точку пересечения перпендикуляра и отрезка
		if (!(t >= 0 && t <= 1) && j < M - 2) {
			j++;
			goto A;
		}

		// расстояние от точки траектории до плана
		dist = sqrt(pow(dotsT[i][0] - pX, 2) + pow(dotsT[i][1] - pY, 2) + pow(dotsT[i][2] - pZ, 2));

		// проверяем, отклонение траектории от плана больше допустимого или нет
		if (dist > maxDev) {
			// отмечаем тревожные точки красным цветом
			chartUp->Series["SeriesDots"]->Points[i]->MarkerColor = Color::Red;
			chartSide->Series["SeriesDots"]->Points[i]->MarkerColor = Color::Red;
		}
	}

	// вычисление середин интервалов по трем осям для построения 3д-графика
	massC[0] = (minX + maxX) / 2;
	massC[1] = (minY + maxY) / 2;
	massC[2] = (minZ + maxZ) / 2;

	// установление масштаба 3д-графика относительно центра построенного графика
	chart1->ChartAreas[0]->AxisX->Minimum = massC[0] - 100;
	chart1->ChartAreas[0]->AxisX->Maximum = massC[0] + 100;
	chart1->ChartAreas[0]->AxisY->Minimum = massC[2] - 100;
	chart1->ChartAreas[0]->AxisY->Maximum = massC[2] + 100;

}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие при нажатии кнопки "Динамическое построение траектории"
	//

	chartUp->Series["SeriesDots"]->Points->Clear();
	chartSide->Series["SeriesDots"]->Points->Clear();
	chart1->Series[1]->Points->Clear();

	double a = Convert::ToDouble(numericUpDownX->Value) * 3.14 / 180;	// угол поворота по оси Х в радианах
	double b = Convert::ToDouble(numericUpDownY->Value) * 3.14 / 180;	// угол поворота по оси Y в радианах
	double c = Convert::ToDouble(numericUpDownZ->Value) * 3.14 / 180;	// угол поворота по оси Z в радианах

	double xc = massC[0];
	double zc = massC[2];

	for (int i = 0; i < N; i++)
	{
		// вывод точек траектории на 2д-график
		chartUp->Series["SeriesDots"]->Points->AddXY(dotsT[i][0], dotsT[i][1]);
		chartSide->Series["SeriesDots"]->Points->AddXY(dotsT[i][0], dotsT[i][2]);

		// вывод точек траектории на 3д-график
		double x = dotsT[i][0];
		double y = dotsT[i][1];
		double z = dotsT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[1]->Points->AddXY(xN, zN);

		// приостановка на 250 миллисекунд
		chartUp->Refresh();
		chartSide->Refresh();
		chart1->Refresh();
		Sleep(250);
	}
}

private: System::Void numericUpDownX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие при измении значения угла поворота по оси Х
	//

	double a = Convert::ToDouble(numericUpDownX->Value) * 3.14 / 180;	// угол поворота по оси Х в радианах
	double b = Convert::ToDouble(numericUpDownY->Value) * 3.14 / 180;	// угол поворота по оси Y в радианах
	double c = Convert::ToDouble(numericUpDownZ->Value) * 3.14 / 180;	// угол поворота по оси Z в радианах

	chart1->Series[0]->Points->Clear();
	chart1->Series[1]->Points->Clear();

	double xc = massC[0];
	double zc = massC[2];

	// вычисление положения точек траектории при измении угла поворота
	for (int i = 0; i < N; i++)
	{
		double x = dotsT[i][0];
		double y = dotsT[i][1];
		double z = dotsT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[1]->Points->AddXY(xN, zN);	// вывод точек траектории на график
	}

	// вычисление положения точек плана при измении угла поворота
	for (int i = 0; i < M; i++)
	{
		double x = planT[i][0];
		double y = planT[i][1];
		double z = planT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[0]->Points->AddXY(xN, zN);	// вывод точек плана на график
	}

	chart1->Refresh();
	Sleep(50);

}
private: System::Void numericUpDownY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие при измении значения угла поворота по оси Y
	//

	double a = Convert::ToDouble(numericUpDownX->Value) * 3.14 / 180;	// угол поворота по оси Х в радианах
	double b = Convert::ToDouble(numericUpDownY->Value) * 3.14 / 180;	// угол поворота по оси Y в радианах
	double c = Convert::ToDouble(numericUpDownZ->Value) * 3.14 / 180;	// угол поворота по оси Z в радианах

	chart1->Series[0]->Points->Clear();
	chart1->Series[1]->Points->Clear();

	double xc = massC[0];
	double zc = massC[2];
	// вычисление положения точек траектории при измении угла поворота
	for (int i = 0; i < N; i++)
	{
		double x = dotsT[i][0];
		double y = dotsT[i][1];
		double z = dotsT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[1]->Points->AddXY(xN, zN);	// вывод точек траектории на график
	}
	// вычисление положения точек плана при измении угла поворота
	for (int i = 0; i < M; i++)
	{
		double x = planT[i][0];
		double y = planT[i][1];
		double z = planT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[0]->Points->AddXY(xN, zN);	// вывод точек плана на график
	}

	chart1->Refresh();
	Sleep(50);
}
private: System::Void numericUpDownZ_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие при измении значения угла поворота по оси Z
	//

	double a = Convert::ToDouble(numericUpDownX->Value) * 3.14 / 180;	// угол поворота по оси Х в радианах
	double b = Convert::ToDouble(numericUpDownY->Value) * 3.14 / 180;	// угол поворота по оси Y в радианах
	double c = Convert::ToDouble(numericUpDownZ->Value) * 3.14 / 180;	// угол поворота по оси Z в радианах

	chart1->Series[0]->Points->Clear();
	chart1->Series[1]->Points->Clear();

	double xc = massC[0];
	double zc = massC[2];
	// вычисление положения точек траектории при измении угла поворота
	for (int i = 0; i < N; i++)
	{
		double x = dotsT[i][0];
		double y = dotsT[i][1];
		double z = dotsT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[1]->Points->AddXY(xN, zN);	// вывод точек траектории на график
	}
	// вычисление положения точек плана при измении угла поворота
	for (int i = 0; i < M; i++)
	{
		double x = planT[i][0];
		double y = planT[i][1];
		double z = planT[i][2];
		double xN, yN, zN;

		// поворот по оси Х
		xN = x;
		yN = cos(a) * y - sin(a) * (z - zc);
		zN = sin(a) * y + cos(a) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Y
		xN = cos(b) * (x - xc) + sin(b) * (z - zc) + xc;
		yN = y;
		zN = -sin(b) * (x - xc) + cos(b) * (z - zc) + zc;

		x = xN;
		y = yN;
		z = zN;

		// поворот по оси Z
		xN = cos(c) * (x - xc) - sin(c) * y + xc;
		yN = sin(c) * (x - xc) + cos(c) * y;
		zN = z;

		chart1->Series[0]->Points->AddXY(xN, zN);	// вывод точек плана на график
	}

	chart1->Refresh();
	Sleep(50);
}
private: System::Void buttonMplus_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие нажатии кнопки "+" - увеличение масштаба
	//
	if (!(chart1->ChartAreas[0]->AxisX->Maximum < 20)) {

		chart1->ChartAreas[0]->AxisX->Minimum += 10;
		chart1->ChartAreas[0]->AxisX->Maximum -= 10;
		chart1->ChartAreas[0]->AxisY->Minimum += 10;
		chart1->ChartAreas[0]->AxisY->Maximum -= 10;
	}
}
private: System::Void buttonMminus_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Действие нажатии кнопки "-" - уменьшение масштаба
	//
	if (!(chart1->ChartAreas[0]->AxisX->Minimum > 9980)) {
		chart1->ChartAreas[0]->AxisX->Minimum -= 10;
		chart1->ChartAreas[0]->AxisX->Maximum += 10;
		chart1->ChartAreas[0]->AxisY->Minimum -= 10;
		chart1->ChartAreas[0]->AxisY->Maximum += 10;
	}
}
};
}
