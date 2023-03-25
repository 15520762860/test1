#include "mysqltext.h"
#include "ui_mysqltext.h"

mysqltext::mysqltext(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mysqltext)
{
    ui->setupUi(this);
    MainWindow *m_mysql = nullptr;
    m_mysql->mysqlconnect();
    init();
}

mysqltext::~mysqltext()
{
    delete ui;
}

void mysqltext::init()
{
    init_ui();
    connect(ui->btn_return,&QPushButton::clicked,[this](){close();});
    connect(ui->btn_search,&QPushButton::clicked,this,&mysqltext::search);
    connect(ui->btn_add,&QPushButton::clicked,this,&mysqltext::into_add_class);
    connect(ui->btn_delete,&QPushButton::clicked,this,&mysqltext::into_delete_class);
    connect(ui->btn_save,&QPushButton::clicked,this,&mysqltext::btn_save);
    connect(ui->btn_derive,&QPushButton::clicked,this,&mysqltext::derive_clicked);
    connect(ui->btn_testdata,&QPushButton::clicked,this,&::mysqltext::btn_textdata);

}

void mysqltext::init_ui()
{
    ui->cmbox_col->setCurrentIndex(0);
    ui->le_keyword->clear();
    ui->btn_add->setEnabled(true);
    ui->btn_delete->setEnabled(true);

    int col = 9;
    int row = 0;
    ui->tableWidget->setColumnCount(col);
    ui->tableWidget->setRowCount(row);
    QStringList header; //表头写入表格
    header << QString::fromLocal8Bit("姓名") << QString::fromLocal8Bit("地区") << QString::fromLocal8Bit("电话号码") << QString::fromLocal8Bit("性别")
           << QString::fromLocal8Bit("交易日期")<< QString::fromLocal8Bit("交易金额")<< QString::fromLocal8Bit("交易物品")<< QString::fromLocal8Bit("是否结款")
           << QString::fromLocal8Bit("备注");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);   //自动调整宽度
    ui->tableWidget->horizontalHeader()->setStyleSheet("border-bottom-width: 0.5px;border-style: outset;border-color: rgb(229,229,229);");

}

void mysqltext::derive_clicked()
{
    //导出
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (), tr("Files (*.csv)"));
    if (fileName.isEmpty())
        return;
    qDebug()<<fileName;

    //打开.csv文件
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        std::cerr << "Cannot open file for writing: "<< qPrintable(file.errorString()) << std::endl;
        return;
    }
    QTextStream out(&file);
    out << tr("name,") << tr("area,")<< tr("phone_num,")
        << tr("sex,") <<tr("Date,") <<tr("money,")
        <<tr("commodity,")<<tr("Whether_borrow,")<<tr("remarks,")<<"\n";

    //获取表格内容
    int row = ui->tableWidget->rowCount();//表格总行数
    for(int i = 0; i < row; i ++){
        for(int col = 0; col < 9; col++){
            QString string = ui->tableWidget->item(i, col)->text();
            out << string << ",";// 写入文件
        }
        out << "\n";
    }
    QMessageBox::information(this, QString::fromLocal8Bit("保存"), QString::fromLocal8Bit("保存成功"));
    file.close();
}

bool mysqltext::textdate(int n)
{
    // 获取TableWidget对象
    QTableWidget *tableWidget = ui->tableWidget;

    for (int i=0;i<n;i++) {
        //srand(time(0));//种随机数种子
        //百家姓-单姓
        QVector<QString>NA = {QString::fromLocal8Bit("赵"),QString::fromLocal8Bit("钱"),QString::fromLocal8Bit("孙"),QString::fromLocal8Bit("李"),QString::fromLocal8Bit("周"),QString::fromLocal8Bit("吴"),QString::fromLocal8Bit("郑"),QString::fromLocal8Bit("王"),QString::fromLocal8Bit("冯"),QString::fromLocal8Bit("陈"),QString::fromLocal8Bit("褚"),QString::fromLocal8Bit("卫"),QString::fromLocal8Bit("蒋"),QString::fromLocal8Bit("沈"),QString::fromLocal8Bit("韩"),QString::fromLocal8Bit("杨"),QString::fromLocal8Bit("朱"),QString::fromLocal8Bit("秦"),QString::fromLocal8Bit("尤"),QString::fromLocal8Bit("许"),QString::fromLocal8Bit("何"),QString::fromLocal8Bit("吕"),QString::fromLocal8Bit("施"),QString::fromLocal8Bit("张"),QString::fromLocal8Bit("孔"),QString::fromLocal8Bit("曹"),QString::fromLocal8Bit("严"),QString::fromLocal8Bit("华"),QString::fromLocal8Bit("金"),QString::fromLocal8Bit("魏"),QString::fromLocal8Bit("陶"),QString::fromLocal8Bit("姜"),QString::fromLocal8Bit("戚"),QString::fromLocal8Bit("谢"),QString::fromLocal8Bit("邹"),QString::fromLocal8Bit("喻"),QString::fromLocal8Bit("柏"),QString::fromLocal8Bit("水"),QString::fromLocal8Bit("窦"),QString::fromLocal8Bit("章"),QString::fromLocal8Bit("云"),QString::fromLocal8Bit("苏"),QString::fromLocal8Bit("潘"),QString::fromLocal8Bit("葛"),QString::fromLocal8Bit("奚"),QString::fromLocal8Bit("范"),QString::fromLocal8Bit("彭"),QString::fromLocal8Bit("郎"),QString::fromLocal8Bit("鲁"),QString::fromLocal8Bit("韦"),QString::fromLocal8Bit("昌"),QString::fromLocal8Bit("马"),QString::fromLocal8Bit("苗"),QString::fromLocal8Bit("凤"),QString::fromLocal8Bit("花"),QString::fromLocal8Bit("方"),QString::fromLocal8Bit("俞"),QString::fromLocal8Bit("任"),QString::fromLocal8Bit("袁"),QString::fromLocal8Bit("柳"),QString::fromLocal8Bit("酆"),QString::fromLocal8Bit("鲍"),QString::fromLocal8Bit("史"),QString::fromLocal8Bit("唐"),QString::fromLocal8Bit("费"),QString::fromLocal8Bit("廉"),QString::fromLocal8Bit("岑"),QString::fromLocal8Bit("薛"),QString::fromLocal8Bit("雷"),QString::fromLocal8Bit("贺"),QString::fromLocal8Bit("倪"),QString::fromLocal8Bit("汤"),QString::fromLocal8Bit("滕"),QString::fromLocal8Bit("殷"),QString::fromLocal8Bit("罗"),QString::fromLocal8Bit("毕"),QString::fromLocal8Bit("郝"),QString::fromLocal8Bit("邬"),QString::fromLocal8Bit("安"),QString::fromLocal8Bit("常"),QString::fromLocal8Bit("乐"),QString::fromLocal8Bit("于"),QString::fromLocal8Bit("时"),QString::fromLocal8Bit("傅"),QString::fromLocal8Bit("皮"),QString::fromLocal8Bit("卞"),QString::fromLocal8Bit("齐"),QString::fromLocal8Bit("康"),QString::fromLocal8Bit("伍"),QString::fromLocal8Bit("余"),QString::fromLocal8Bit("元"),QString::fromLocal8Bit("卜"),QString::fromLocal8Bit("顾"),QString::fromLocal8Bit("孟"),QString::fromLocal8Bit("平"),QString::fromLocal8Bit("黄"),QString::fromLocal8Bit("和"),QString::fromLocal8Bit("穆"),QString::fromLocal8Bit("萧"),QString::fromLocal8Bit("尹"),QString::fromLocal8Bit("姚"),QString::fromLocal8Bit("邵"),QString::fromLocal8Bit("湛"),QString::fromLocal8Bit("汪"),QString::fromLocal8Bit("祁"),QString::fromLocal8Bit("毛"),QString::fromLocal8Bit("禹"),QString::fromLocal8Bit("狄"),QString::fromLocal8Bit("米"),QString::fromLocal8Bit("贝"),QString::fromLocal8Bit("明"),QString::fromLocal8Bit("臧"),QString::fromLocal8Bit("计"),QString::fromLocal8Bit("伏"),QString::fromLocal8Bit("成"),QString::fromLocal8Bit("戴"),QString::fromLocal8Bit("谈"),QString::fromLocal8Bit("宋"),QString::fromLocal8Bit("茅"),QString::fromLocal8Bit("庞"),QString::fromLocal8Bit("熊"),QString::fromLocal8Bit("纪"),QString::fromLocal8Bit("舒"),QString::fromLocal8Bit("屈"),QString::fromLocal8Bit("项"),QString::fromLocal8Bit("祝"),QString::fromLocal8Bit("董"),QString::fromLocal8Bit("梁"),QString::fromLocal8Bit("杜"),QString::fromLocal8Bit("阮"),QString::fromLocal8Bit("蓝"),QString::fromLocal8Bit("闵"),QString::fromLocal8Bit("席"),QString::fromLocal8Bit("季"),QString::fromLocal8Bit("麻"),QString::fromLocal8Bit("强"),QString::fromLocal8Bit("贾"),QString::fromLocal8Bit("路"),QString::fromLocal8Bit("娄"),QString::fromLocal8Bit("危"),QString::fromLocal8Bit("江"),QString::fromLocal8Bit("童"),QString::fromLocal8Bit("颜"),QString::fromLocal8Bit("郭"),QString::fromLocal8Bit("梅"),QString::fromLocal8Bit("盛"),QString::fromLocal8Bit("林"),QString::fromLocal8Bit("刁"),QString::fromLocal8Bit("钟"),QString::fromLocal8Bit("徐"),QString::fromLocal8Bit("邱"),QString::fromLocal8Bit("骆"),QString::fromLocal8Bit("高"),QString::fromLocal8Bit("夏"),QString::fromLocal8Bit("蔡"),QString::fromLocal8Bit("田"),QString::fromLocal8Bit("樊"),QString::fromLocal8Bit("胡"),QString::fromLocal8Bit("凌"),QString::fromLocal8Bit("霍"),QString::fromLocal8Bit("虞"),QString::fromLocal8Bit("万"),QString::fromLocal8Bit("支"),QString::fromLocal8Bit("柯"),QString::fromLocal8Bit("昝"),QString::fromLocal8Bit("管"),QString::fromLocal8Bit("卢"),QString::fromLocal8Bit("莫"),QString::fromLocal8Bit("经"),QString::fromLocal8Bit("房"),QString::fromLocal8Bit("裘"),QString::fromLocal8Bit("缪"),QString::fromLocal8Bit("干"),QString::fromLocal8Bit("解"),QString::fromLocal8Bit("应"),QString::fromLocal8Bit("宗"),QString::fromLocal8Bit("丁"),QString::fromLocal8Bit("宣"),QString::fromLocal8Bit("贲"),QString::fromLocal8Bit("邓"),QString::fromLocal8Bit("郁"),QString::fromLocal8Bit("单"),QString::fromLocal8Bit("杭"),QString::fromLocal8Bit("洪"),QString::fromLocal8Bit("包"),QString::fromLocal8Bit("诸"),QString::fromLocal8Bit("左"),QString::fromLocal8Bit("石"),QString::fromLocal8Bit("崔"),QString::fromLocal8Bit("吉"),QString::fromLocal8Bit("钮"),QString::fromLocal8Bit("龚"),QString::fromLocal8Bit("程"),QString::fromLocal8Bit("嵇"),QString::fromLocal8Bit("邢"),QString::fromLocal8Bit("滑"),QString::fromLocal8Bit("裴"),QString::fromLocal8Bit("陆"),QString::fromLocal8Bit("荣"),QString::fromLocal8Bit("翁"),QString::fromLocal8Bit("荀"),QString::fromLocal8Bit("羊"),QString::fromLocal8Bit("於"),QString::fromLocal8Bit("惠"),QString::fromLocal8Bit("甄"),QString::fromLocal8Bit("麴"),QString::fromLocal8Bit("家"),QString::fromLocal8Bit("封"),QString::fromLocal8Bit("芮"),QString::fromLocal8Bit("羿"),QString::fromLocal8Bit("储"),QString::fromLocal8Bit("靳"),QString::fromLocal8Bit("汲"),QString::fromLocal8Bit("邴"),QString::fromLocal8Bit("糜"),QString::fromLocal8Bit("松"),QString::fromLocal8Bit("井"),QString::fromLocal8Bit("段"),QString::fromLocal8Bit("富"),QString::fromLocal8Bit("巫"),QString::fromLocal8Bit("乌"),QString::fromLocal8Bit("焦"),QString::fromLocal8Bit("巴"),QString::fromLocal8Bit("弓"),QString::fromLocal8Bit("牧"),QString::fromLocal8Bit("隗"),QString::fromLocal8Bit("山"),QString::fromLocal8Bit("谷"),QString::fromLocal8Bit("车"),QString::fromLocal8Bit("侯"),QString::fromLocal8Bit("宓"),QString::fromLocal8Bit("蓬"),QString::fromLocal8Bit("全"),QString::fromLocal8Bit("郗"),QString::fromLocal8Bit("班"),QString::fromLocal8Bit("仰"),QString::fromLocal8Bit("秋"),QString::fromLocal8Bit("仲"),QString::fromLocal8Bit("伊"),QString::fromLocal8Bit("宫"),QString::fromLocal8Bit("宁"),QString::fromLocal8Bit("仇"),QString::fromLocal8Bit("栾"),QString::fromLocal8Bit("暴"),QString::fromLocal8Bit("甘"),QString::fromLocal8Bit("钭"),QString::fromLocal8Bit("厉"),QString::fromLocal8Bit("戎"),QString::fromLocal8Bit("祖"),QString::fromLocal8Bit("武"),QString::fromLocal8Bit("符"),QString::fromLocal8Bit("刘"),QString::fromLocal8Bit("景"),QString::fromLocal8Bit("詹"),QString::fromLocal8Bit("束"),QString::fromLocal8Bit("龙"),QString::fromLocal8Bit("叶"),QString::fromLocal8Bit("幸"),QString::fromLocal8Bit("司"),QString::fromLocal8Bit("韶"),QString::fromLocal8Bit("郜"),QString::fromLocal8Bit("黎"),QString::fromLocal8Bit("蓟"),QString::fromLocal8Bit("薄"),QString::fromLocal8Bit("印"),QString::fromLocal8Bit("宿"),QString::fromLocal8Bit("白"),QString::fromLocal8Bit("怀"),QString::fromLocal8Bit("蒲"),QString::fromLocal8Bit("邰"),QString::fromLocal8Bit("从"),QString::fromLocal8Bit("鄂"),QString::fromLocal8Bit("索"),QString::fromLocal8Bit("咸"),QString::fromLocal8Bit("籍"),QString::fromLocal8Bit("赖"),QString::fromLocal8Bit("卓"),QString::fromLocal8Bit("蔺"),QString::fromLocal8Bit("屠"),QString::fromLocal8Bit("蒙"),QString::fromLocal8Bit("池"),QString::fromLocal8Bit("乔"),QString::fromLocal8Bit("阴"),QString::fromLocal8Bit("郁"),QString::fromLocal8Bit("胥"),QString::fromLocal8Bit("能"),QString::fromLocal8Bit("苍"),QString::fromLocal8Bit("双"),QString::fromLocal8Bit("闻"),QString::fromLocal8Bit("莘"),QString::fromLocal8Bit("党"),QString::fromLocal8Bit("翟"),QString::fromLocal8Bit("谭"),QString::fromLocal8Bit("贡"),QString::fromLocal8Bit("劳"),QString::fromLocal8Bit("逄"),QString::fromLocal8Bit("姬"),QString::fromLocal8Bit("申"),QString::fromLocal8Bit("扶"),QString::fromLocal8Bit("堵"),QString::fromLocal8Bit("冉"),QString::fromLocal8Bit("宰"),QString::fromLocal8Bit("郦"),QString::fromLocal8Bit("雍"),QString::fromLocal8Bit("舄"),QString::fromLocal8Bit("璩"),QString::fromLocal8Bit("桑"),QString::fromLocal8Bit("桂"),QString::fromLocal8Bit("濮"),QString::fromLocal8Bit("牛"),QString::fromLocal8Bit("寿"),QString::fromLocal8Bit("通"),QString::fromLocal8Bit("边"),QString::fromLocal8Bit("扈"),QString::fromLocal8Bit("燕"),QString::fromLocal8Bit("冀"),QString::fromLocal8Bit("郏"),QString::fromLocal8Bit("浦"),QString::fromLocal8Bit("尚"),QString::fromLocal8Bit("农"),QString::fromLocal8Bit("温"),QString::fromLocal8Bit("别"),QString::fromLocal8Bit("庄"),QString::fromLocal8Bit("晏"),QString::fromLocal8Bit("柴"),QString::fromLocal8Bit("瞿"),QString::fromLocal8Bit("阎"),QString::fromLocal8Bit("充"),QString::fromLocal8Bit("慕"),QString::fromLocal8Bit("连"),QString::fromLocal8Bit("茹"),QString::fromLocal8Bit("习"),QString::fromLocal8Bit("宦"),QString::fromLocal8Bit("艾"),QString::fromLocal8Bit("鱼"),QString::fromLocal8Bit("容"),QString::fromLocal8Bit("向"),QString::fromLocal8Bit("古"),QString::fromLocal8Bit("易"),QString::fromLocal8Bit("慎"),QString::fromLocal8Bit("戈"),QString::fromLocal8Bit("廖"),QString::fromLocal8Bit("庾"),QString::fromLocal8Bit("终"),QString::fromLocal8Bit("暨"),QString::fromLocal8Bit("居"),QString::fromLocal8Bit("衡"),QString::fromLocal8Bit("步"),QString::fromLocal8Bit("都"),QString::fromLocal8Bit("耿"),QString::fromLocal8Bit("满"),QString::fromLocal8Bit("弘"),QString::fromLocal8Bit("匡"),QString::fromLocal8Bit("国"),QString::fromLocal8Bit("文"),QString::fromLocal8Bit("寇"),QString::fromLocal8Bit("广"),QString::fromLocal8Bit("禄"),QString::fromLocal8Bit("阙"),QString::fromLocal8Bit("东"),QString::fromLocal8Bit("殴"),QString::fromLocal8Bit("殳"),QString::fromLocal8Bit("沃"),QString::fromLocal8Bit("利"),QString::fromLocal8Bit("蔚"),QString::fromLocal8Bit("越"),QString::fromLocal8Bit("夔"),QString::fromLocal8Bit("隆"),QString::fromLocal8Bit("师"),QString::fromLocal8Bit("巩"),QString::fromLocal8Bit("厍"),QString::fromLocal8Bit("聂"),QString::fromLocal8Bit("晁"),QString::fromLocal8Bit("勾"),QString::fromLocal8Bit("敖"),QString::fromLocal8Bit("融"),QString::fromLocal8Bit("冷"),QString::fromLocal8Bit("訾"),QString::fromLocal8Bit("辛"),QString::fromLocal8Bit("阚"),QString::fromLocal8Bit("那"),QString::fromLocal8Bit("简"),QString::fromLocal8Bit("饶"),QString::fromLocal8Bit("空"),QString::fromLocal8Bit("曾"),QString::fromLocal8Bit("毋"),QString::fromLocal8Bit("沙"),QString::fromLocal8Bit("乜"),QString::fromLocal8Bit("养"),QString::fromLocal8Bit("鞠"),QString::fromLocal8Bit("须"),QString::fromLocal8Bit("丰"),QString::fromLocal8Bit("巢"),QString::fromLocal8Bit("关"),QString::fromLocal8Bit("蒯"),QString::fromLocal8Bit("相"),QString::fromLocal8Bit("查"),QString::fromLocal8Bit("後"),QString::fromLocal8Bit("荆"),QString::fromLocal8Bit("红"),QString::fromLocal8Bit("游"),QString::fromLocal8Bit("竺"),QString::fromLocal8Bit("权"),QString::fromLocal8Bit("逯"),QString::fromLocal8Bit("盖"),QString::fromLocal8Bit("益"),QString::fromLocal8Bit("桓"),QString::fromLocal8Bit("公"),QString::fromLocal8Bit("仉"),QString::fromLocal8Bit("督"),QString::fromLocal8Bit("晋"),QString::fromLocal8Bit("楚"),QString::fromLocal8Bit("闫"),QString::fromLocal8Bit("法"),QString::fromLocal8Bit("汝"),QString::fromLocal8Bit("鄢"),QString::fromLocal8Bit("涂"),QString::fromLocal8Bit("钦"),QString::fromLocal8Bit("归"),QString::fromLocal8Bit("海"),QString::fromLocal8Bit("岳"),QString::fromLocal8Bit("帅"),QString::fromLocal8Bit("缑"),QString::fromLocal8Bit("亢"),QString::fromLocal8Bit("况"),QString::fromLocal8Bit("后"),QString::fromLocal8Bit("有"),QString::fromLocal8Bit("琴"),QString::fromLocal8Bit("商"),QString::fromLocal8Bit("牟"),QString::fromLocal8Bit("佘"),QString::fromLocal8Bit("佴"),QString::fromLocal8Bit("伯"),QString::fromLocal8Bit("赏"),QString::fromLocal8Bit("墨"),QString::fromLocal8Bit("哈"),QString::fromLocal8Bit("谯"),QString::fromLocal8Bit("笪"),QString::fromLocal8Bit("年"),QString::fromLocal8Bit("爱"),QString::fromLocal8Bit("阳"),QString::fromLocal8Bit("佟"),QString::fromLocal8Bit("言"),QString::fromLocal8Bit("福")};
        //百家姓-复姓
        QVector<QString>NAs = {QString::fromLocal8Bit("万俟"),QString::fromLocal8Bit("司马"),QString::fromLocal8Bit("上官"),QString::fromLocal8Bit("欧阳"),QString::fromLocal8Bit("夏侯"),QString::fromLocal8Bit("诸葛"),QString::fromLocal8Bit("闻人"),QString::fromLocal8Bit("东方"),QString::fromLocal8Bit("赫连"),QString::fromLocal8Bit("皇甫"),QString::fromLocal8Bit("尉迟"),QString::fromLocal8Bit("公羊"),QString::fromLocal8Bit("澹台"),QString::fromLocal8Bit("公冶"),QString::fromLocal8Bit("宗政"),QString::fromLocal8Bit("濮阳"),QString::fromLocal8Bit("淳于"),QString::fromLocal8Bit("单于"),QString::fromLocal8Bit("太叔"),QString::fromLocal8Bit("申屠"),QString::fromLocal8Bit("公孙"),QString::fromLocal8Bit("仲孙"),QString::fromLocal8Bit("轩辕"),QString::fromLocal8Bit("令狐"),QString::fromLocal8Bit("钟离"),QString::fromLocal8Bit("宇文"),QString::fromLocal8Bit("长孙"),QString::fromLocal8Bit("慕容"),QString::fromLocal8Bit("鲜于"),QString::fromLocal8Bit("闾丘"),QString::fromLocal8Bit("司徒"),QString::fromLocal8Bit("司空"),QString::fromLocal8Bit("亓官"),QString::fromLocal8Bit("司寇"),QString::fromLocal8Bit("子车"),QString::fromLocal8Bit("颛孙"),QString::fromLocal8Bit("端木"),QString::fromLocal8Bit("巫马"),QString::fromLocal8Bit("公西"),QString::fromLocal8Bit("漆雕"),QString::fromLocal8Bit("乐正"),QString::fromLocal8Bit("壤驷"),QString::fromLocal8Bit("公良"),QString::fromLocal8Bit("拓跋"),QString::fromLocal8Bit("夹谷"),QString::fromLocal8Bit("宰父"),QString::fromLocal8Bit("谷梁"),QString::fromLocal8Bit("百里"),QString::fromLocal8Bit("东郭"),QString::fromLocal8Bit("南门"),QString::fromLocal8Bit("呼延"),QString::fromLocal8Bit("羊舌"),QString::fromLocal8Bit("微生"),QString::fromLocal8Bit("梁丘"),QString::fromLocal8Bit("左丘"),QString::fromLocal8Bit("东门"),QString::fromLocal8Bit("西门"),QString::fromLocal8Bit("南宫"),QString::fromLocal8Bit("第五")};
        //男性常用名
        QVector<QString>NA1 = {QString::fromLocal8Bit("伟"),QString::fromLocal8Bit("刚"),QString::fromLocal8Bit("勇"),QString::fromLocal8Bit("毅"),QString::fromLocal8Bit("俊"),QString::fromLocal8Bit("峰"),QString::fromLocal8Bit("强"),QString::fromLocal8Bit("军"),QString::fromLocal8Bit("平"),QString::fromLocal8Bit("保"),QString::fromLocal8Bit("东"),QString::fromLocal8Bit("文"),QString::fromLocal8Bit("辉"),QString::fromLocal8Bit("力"),QString::fromLocal8Bit("明"),QString::fromLocal8Bit("永"),QString::fromLocal8Bit("健"),QString::fromLocal8Bit("世"),QString::fromLocal8Bit("广"),QString::fromLocal8Bit("志"),QString::fromLocal8Bit("义"),QString::fromLocal8Bit("兴"),QString::fromLocal8Bit("良"),QString::fromLocal8Bit("海"),QString::fromLocal8Bit("山"),QString::fromLocal8Bit("仁"),QString::fromLocal8Bit("波"),QString::fromLocal8Bit("宁"),QString::fromLocal8Bit("贵"),QString::fromLocal8Bit("福"),QString::fromLocal8Bit("生"),QString::fromLocal8Bit("龙"),QString::fromLocal8Bit("元"),QString::fromLocal8Bit("全"),QString::fromLocal8Bit("国"),QString::fromLocal8Bit("胜"),QString::fromLocal8Bit("学"),QString::fromLocal8Bit("祥"),QString::fromLocal8Bit("才"),QString::fromLocal8Bit("发"),QString::fromLocal8Bit("武"),QString::fromLocal8Bit("新"),QString::fromLocal8Bit("利"),QString::fromLocal8Bit("清"),QString::fromLocal8Bit("飞"),QString::fromLocal8Bit("彬"),QString::fromLocal8Bit("富"),QString::fromLocal8Bit("顺"),QString::fromLocal8Bit("信"),QString::fromLocal8Bit("子"),QString::fromLocal8Bit("杰"),QString::fromLocal8Bit("涛"),QString::fromLocal8Bit("昌"),QString::fromLocal8Bit("成"),QString::fromLocal8Bit("康"),QString::fromLocal8Bit("星"),QString::fromLocal8Bit("光"),QString::fromLocal8Bit("天"),QString::fromLocal8Bit("达"),QString::fromLocal8Bit("安"),QString::fromLocal8Bit("岩"),QString::fromLocal8Bit("中"),QString::fromLocal8Bit("茂"),QString::fromLocal8Bit("进"),QString::fromLocal8Bit("林"),QString::fromLocal8Bit("有"),QString::fromLocal8Bit("坚"),QString::fromLocal8Bit("和"),QString::fromLocal8Bit("彪"),QString::fromLocal8Bit("博"),QString::fromLocal8Bit("诚"),QString::fromLocal8Bit("先"),QString::fromLocal8Bit("敬"),QString::fromLocal8Bit("震"),QString::fromLocal8Bit("振"),QString::fromLocal8Bit("壮"),QString::fromLocal8Bit("会"),QString::fromLocal8Bit("思"),QString::fromLocal8Bit("群"),QString::fromLocal8Bit("豪"),QString::fromLocal8Bit("心"),QString::fromLocal8Bit("邦"),QString::fromLocal8Bit("承"),QString::fromLocal8Bit("乐"),QString::fromLocal8Bit("绍"),QString::fromLocal8Bit("功"),QString::fromLocal8Bit("松"),QString::fromLocal8Bit("善"),QString::fromLocal8Bit("厚"),QString::fromLocal8Bit("庆"),QString::fromLocal8Bit("磊"),QString::fromLocal8Bit("民"),QString::fromLocal8Bit("友"),QString::fromLocal8Bit("裕"),QString::fromLocal8Bit("河"),QString::fromLocal8Bit("哲"),QString::fromLocal8Bit("江"),QString::fromLocal8Bit("超"),QString::fromLocal8Bit("浩"),QString::fromLocal8Bit("亮"),QString::fromLocal8Bit("政"),QString::fromLocal8Bit("谦"),QString::fromLocal8Bit("亨"),QString::fromLocal8Bit("奇"),QString::fromLocal8Bit("固"),QString::fromLocal8Bit("之"),QString::fromLocal8Bit("轮"),QString::fromLocal8Bit("翰"),QString::fromLocal8Bit("朗"),QString::fromLocal8Bit("伯"),QString::fromLocal8Bit("宏"),QString::fromLocal8Bit("言"),QString::fromLocal8Bit("若"),QString::fromLocal8Bit("鸣"),QString::fromLocal8Bit("朋"),QString::fromLocal8Bit("斌"),QString::fromLocal8Bit("梁"),QString::fromLocal8Bit("栋"),QString::fromLocal8Bit("维"),QString::fromLocal8Bit("启"),QString::fromLocal8Bit("克"),QString::fromLocal8Bit("伦"),QString::fromLocal8Bit("翔"),QString::fromLocal8Bit("旭"),QString::fromLocal8Bit("鹏"),QString::fromLocal8Bit("泽"),QString::fromLocal8Bit("晨"),QString::fromLocal8Bit("辰"),QString::fromLocal8Bit("士"),QString::fromLocal8Bit("以"),QString::fromLocal8Bit("建"),QString::fromLocal8Bit("家"),QString::fromLocal8Bit("致"),QString::fromLocal8Bit("树"),QString::fromLocal8Bit("炎"),QString::fromLocal8Bit("德"),QString::fromLocal8Bit("行"),QString::fromLocal8Bit("时"),QString::fromLocal8Bit("泰"),QString::fromLocal8Bit("盛")};
        QVector<QString>NA2 = {QString::fromLocal8Bit("伟"),QString::fromLocal8Bit("刚"),QString::fromLocal8Bit("勇"),QString::fromLocal8Bit("毅"),QString::fromLocal8Bit("俊"),QString::fromLocal8Bit("峰"),QString::fromLocal8Bit("强"),QString::fromLocal8Bit("军"),QString::fromLocal8Bit("平"),QString::fromLocal8Bit("保"),QString::fromLocal8Bit("东"),QString::fromLocal8Bit("文"),QString::fromLocal8Bit("辉"),QString::fromLocal8Bit("力"),QString::fromLocal8Bit("明"),QString::fromLocal8Bit("永"),QString::fromLocal8Bit("健"),QString::fromLocal8Bit("世"),QString::fromLocal8Bit("广"),QString::fromLocal8Bit("志"),QString::fromLocal8Bit("义"),QString::fromLocal8Bit("兴"),QString::fromLocal8Bit("良"),QString::fromLocal8Bit("海"),QString::fromLocal8Bit("山"),QString::fromLocal8Bit("仁"),QString::fromLocal8Bit("波"),QString::fromLocal8Bit("宁"),QString::fromLocal8Bit("贵"),QString::fromLocal8Bit("福"),QString::fromLocal8Bit("生"),QString::fromLocal8Bit("龙"),QString::fromLocal8Bit("元"),QString::fromLocal8Bit("全"),QString::fromLocal8Bit("国"),QString::fromLocal8Bit("胜"),QString::fromLocal8Bit("学"),QString::fromLocal8Bit("祥"),QString::fromLocal8Bit("才"),QString::fromLocal8Bit("发"),QString::fromLocal8Bit("武"),QString::fromLocal8Bit("新"),QString::fromLocal8Bit("利"),QString::fromLocal8Bit("清"),QString::fromLocal8Bit("飞"),QString::fromLocal8Bit("彬"),QString::fromLocal8Bit("富"),QString::fromLocal8Bit("顺"),QString::fromLocal8Bit("信"),QString::fromLocal8Bit("子"),QString::fromLocal8Bit("杰"),QString::fromLocal8Bit("涛"),QString::fromLocal8Bit("昌"),QString::fromLocal8Bit("成"),QString::fromLocal8Bit("康"),QString::fromLocal8Bit("星"),QString::fromLocal8Bit("光"),QString::fromLocal8Bit("天"),QString::fromLocal8Bit("达"),QString::fromLocal8Bit("安"),QString::fromLocal8Bit("岩"),QString::fromLocal8Bit("中"),QString::fromLocal8Bit("茂"),QString::fromLocal8Bit("进"),QString::fromLocal8Bit("林"),QString::fromLocal8Bit("有"),QString::fromLocal8Bit("坚"),QString::fromLocal8Bit("和"),QString::fromLocal8Bit("彪"),QString::fromLocal8Bit("博"),QString::fromLocal8Bit("诚"),QString::fromLocal8Bit("先"),QString::fromLocal8Bit("敬"),QString::fromLocal8Bit("震"),QString::fromLocal8Bit("振"),QString::fromLocal8Bit("壮"),QString::fromLocal8Bit("会"),QString::fromLocal8Bit("思"),QString::fromLocal8Bit("群"),QString::fromLocal8Bit("豪"),QString::fromLocal8Bit("心"),QString::fromLocal8Bit("邦"),QString::fromLocal8Bit("承"),QString::fromLocal8Bit("乐"),QString::fromLocal8Bit("绍"),QString::fromLocal8Bit("功"),QString::fromLocal8Bit("松"),QString::fromLocal8Bit("善"),QString::fromLocal8Bit("厚"),QString::fromLocal8Bit("庆"),QString::fromLocal8Bit("磊"),QString::fromLocal8Bit("民"),QString::fromLocal8Bit("友"),QString::fromLocal8Bit("裕"),QString::fromLocal8Bit("河"),QString::fromLocal8Bit("哲"),QString::fromLocal8Bit("江"),QString::fromLocal8Bit("超"),QString::fromLocal8Bit("浩"),QString::fromLocal8Bit("亮"),QString::fromLocal8Bit("政"),QString::fromLocal8Bit("谦"),QString::fromLocal8Bit("亨"),QString::fromLocal8Bit("奇"),QString::fromLocal8Bit("固"),QString::fromLocal8Bit("之"),QString::fromLocal8Bit("轮"),QString::fromLocal8Bit("翰"),QString::fromLocal8Bit("朗"),QString::fromLocal8Bit("伯"),QString::fromLocal8Bit("宏"),QString::fromLocal8Bit("言"),QString::fromLocal8Bit("若"),QString::fromLocal8Bit("鸣"),QString::fromLocal8Bit("朋"),QString::fromLocal8Bit("斌"),QString::fromLocal8Bit("梁"),QString::fromLocal8Bit("栋"),QString::fromLocal8Bit("维"),QString::fromLocal8Bit("启"),QString::fromLocal8Bit("克"),QString::fromLocal8Bit("伦"),QString::fromLocal8Bit("翔"),QString::fromLocal8Bit("旭"),QString::fromLocal8Bit("鹏"),QString::fromLocal8Bit("泽"),QString::fromLocal8Bit("晨"),QString::fromLocal8Bit("辰"),QString::fromLocal8Bit("士"),QString::fromLocal8Bit("以"),QString::fromLocal8Bit("建"),QString::fromLocal8Bit("家"),QString::fromLocal8Bit("致"),QString::fromLocal8Bit("树"),QString::fromLocal8Bit("炎"),QString::fromLocal8Bit("德"),QString::fromLocal8Bit("行"),QString::fromLocal8Bit("时"),QString::fromLocal8Bit("泰"),QString::fromLocal8Bit("盛")};
        //女性常用名
        QVector<QString>NA3 = {QString::fromLocal8Bit("秀"),QString::fromLocal8Bit("娟"),QString::fromLocal8Bit("英"),QString::fromLocal8Bit("华"),QString::fromLocal8Bit("慧"),QString::fromLocal8Bit("巧"),QString::fromLocal8Bit("美"),QString::fromLocal8Bit("娜"),QString::fromLocal8Bit("静"),QString::fromLocal8Bit("淑"),QString::fromLocal8Bit("惠"),QString::fromLocal8Bit("珠"),QString::fromLocal8Bit("翠"),QString::fromLocal8Bit("雅"),QString::fromLocal8Bit("芝"),QString::fromLocal8Bit("玉"),QString::fromLocal8Bit("萍"),QString::fromLocal8Bit("红"),QString::fromLocal8Bit("娥"),QString::fromLocal8Bit("玲"),QString::fromLocal8Bit("芬"),QString::fromLocal8Bit("芳"),QString::fromLocal8Bit("燕"),QString::fromLocal8Bit("彩"),QString::fromLocal8Bit("春"),QString::fromLocal8Bit("菊"),QString::fromLocal8Bit("兰"),QString::fromLocal8Bit("凤"),QString::fromLocal8Bit("洁"),QString::fromLocal8Bit("梅"),QString::fromLocal8Bit("琳"),QString::fromLocal8Bit("素"),QString::fromLocal8Bit("云"),QString::fromLocal8Bit("莲"),QString::fromLocal8Bit("真"),QString::fromLocal8Bit("环"),QString::fromLocal8Bit("雪"),QString::fromLocal8Bit("荣"),QString::fromLocal8Bit("爱"),QString::fromLocal8Bit("妹"),QString::fromLocal8Bit("霞"),QString::fromLocal8Bit("香"),QString::fromLocal8Bit("月"),QString::fromLocal8Bit("莺"),QString::fromLocal8Bit("媛"),QString::fromLocal8Bit("艳"),QString::fromLocal8Bit("瑞"),QString::fromLocal8Bit("凡"),QString::fromLocal8Bit("佳"),QString::fromLocal8Bit("嘉"),QString::fromLocal8Bit("琼"),QString::fromLocal8Bit("勤"),QString::fromLocal8Bit("珍"),QString::fromLocal8Bit("贞"),QString::fromLocal8Bit("莉"),QString::fromLocal8Bit("桂"),QString::fromLocal8Bit("娣"),QString::fromLocal8Bit("叶"),QString::fromLocal8Bit("璧"),QString::fromLocal8Bit("璐"),QString::fromLocal8Bit("娅"),QString::fromLocal8Bit("琦"),QString::fromLocal8Bit("晶"),QString::fromLocal8Bit("妍"),QString::fromLocal8Bit("茜"),QString::fromLocal8Bit("秋"),QString::fromLocal8Bit("珊"),QString::fromLocal8Bit("莎"),QString::fromLocal8Bit("锦"),QString::fromLocal8Bit("黛"),QString::fromLocal8Bit("青"),QString::fromLocal8Bit("倩"),QString::fromLocal8Bit("婷"),QString::fromLocal8Bit("姣"),QString::fromLocal8Bit("婉"),QString::fromLocal8Bit("娴"),QString::fromLocal8Bit("瑾"),QString::fromLocal8Bit("颖"),QString::fromLocal8Bit("露"),QString::fromLocal8Bit("瑶"),QString::fromLocal8Bit("怡"),QString::fromLocal8Bit("婵"),QString::fromLocal8Bit("雁"),QString::fromLocal8Bit("蓓"),QString::fromLocal8Bit("纨"),QString::fromLocal8Bit("仪"),QString::fromLocal8Bit("荷"),QString::fromLocal8Bit("丹"),QString::fromLocal8Bit("蓉"),QString::fromLocal8Bit("眉"),QString::fromLocal8Bit("君"),QString::fromLocal8Bit("琴"),QString::fromLocal8Bit("蕊"),QString::fromLocal8Bit("薇"),QString::fromLocal8Bit("菁"),QString::fromLocal8Bit("梦"),QString::fromLocal8Bit("岚"),QString::fromLocal8Bit("苑"),QString::fromLocal8Bit("筠"),QString::fromLocal8Bit("柔"),QString::fromLocal8Bit("竹"),QString::fromLocal8Bit("霭"),QString::fromLocal8Bit("凝"),QString::fromLocal8Bit("晓"),QString::fromLocal8Bit("欢"),QString::fromLocal8Bit("霄"),QString::fromLocal8Bit("枫"),QString::fromLocal8Bit("芸"),QString::fromLocal8Bit("菲"),QString::fromLocal8Bit("寒"),QString::fromLocal8Bit("欣"),QString::fromLocal8Bit("滢"),QString::fromLocal8Bit("伊"),QString::fromLocal8Bit("亚"),QString::fromLocal8Bit("宜"),QString::fromLocal8Bit("可"),QString::fromLocal8Bit("姬"),QString::fromLocal8Bit("舒"),QString::fromLocal8Bit("影"),QString::fromLocal8Bit("荔"),QString::fromLocal8Bit("枝"),QString::fromLocal8Bit("思"),QString::fromLocal8Bit("丽"),QString::fromLocal8Bit("秀"),QString::fromLocal8Bit("飘"),QString::fromLocal8Bit("育"),QString::fromLocal8Bit("馥"),QString::fromLocal8Bit("琦"),QString::fromLocal8Bit("晶"),QString::fromLocal8Bit("妍"),QString::fromLocal8Bit("茜"),QString::fromLocal8Bit("秋"),QString::fromLocal8Bit("珊"),QString::fromLocal8Bit("莎"),QString::fromLocal8Bit("锦"),QString::fromLocal8Bit("黛"),QString::fromLocal8Bit("青"),QString::fromLocal8Bit("倩"),QString::fromLocal8Bit("婷"),QString::fromLocal8Bit("宁"),QString::fromLocal8Bit("蓓"),QString::fromLocal8Bit("纨"),QString::fromLocal8Bit("苑"),QString::fromLocal8Bit("婕"),QString::fromLocal8Bit("馨"),QString::fromLocal8Bit("瑗"),QString::fromLocal8Bit("琰"),QString::fromLocal8Bit("韵"),QString::fromLocal8Bit("融"),QString::fromLocal8Bit("园"),QString::fromLocal8Bit("艺"),QString::fromLocal8Bit("咏"),QString::fromLocal8Bit("卿"),QString::fromLocal8Bit("聪"),QString::fromLocal8Bit("澜"),QString::fromLocal8Bit("纯"),QString::fromLocal8Bit("毓"),QString::fromLocal8Bit("悦"),QString::fromLocal8Bit("昭"),QString::fromLocal8Bit("冰"),QString::fromLocal8Bit("爽"),QString::fromLocal8Bit("琬"),QString::fromLocal8Bit("茗"),QString::fromLocal8Bit("羽"),QString::fromLocal8Bit("希")};
        QVector<QString>NA4 = {QString::fromLocal8Bit("秀"),QString::fromLocal8Bit("娟"),QString::fromLocal8Bit("英"),QString::fromLocal8Bit("华"),QString::fromLocal8Bit("慧"),QString::fromLocal8Bit("巧"),QString::fromLocal8Bit("美"),QString::fromLocal8Bit("娜"),QString::fromLocal8Bit("静"),QString::fromLocal8Bit("淑"),QString::fromLocal8Bit("惠"),QString::fromLocal8Bit("珠"),QString::fromLocal8Bit("翠"),QString::fromLocal8Bit("雅"),QString::fromLocal8Bit("芝"),QString::fromLocal8Bit("玉"),QString::fromLocal8Bit("萍"),QString::fromLocal8Bit("红"),QString::fromLocal8Bit("娥"),QString::fromLocal8Bit("玲"),QString::fromLocal8Bit("芬"),QString::fromLocal8Bit("芳"),QString::fromLocal8Bit("燕"),QString::fromLocal8Bit("彩"),QString::fromLocal8Bit("春"),QString::fromLocal8Bit("菊"),QString::fromLocal8Bit("兰"),QString::fromLocal8Bit("凤"),QString::fromLocal8Bit("洁"),QString::fromLocal8Bit("梅"),QString::fromLocal8Bit("琳"),QString::fromLocal8Bit("素"),QString::fromLocal8Bit("云"),QString::fromLocal8Bit("莲"),QString::fromLocal8Bit("真"),QString::fromLocal8Bit("环"),QString::fromLocal8Bit("雪"),QString::fromLocal8Bit("荣"),QString::fromLocal8Bit("爱"),QString::fromLocal8Bit("妹"),QString::fromLocal8Bit("霞"),QString::fromLocal8Bit("香"),QString::fromLocal8Bit("月"),QString::fromLocal8Bit("莺"),QString::fromLocal8Bit("媛"),QString::fromLocal8Bit("艳"),QString::fromLocal8Bit("瑞"),QString::fromLocal8Bit("凡"),QString::fromLocal8Bit("佳"),QString::fromLocal8Bit("嘉"),QString::fromLocal8Bit("琼"),QString::fromLocal8Bit("勤"),QString::fromLocal8Bit("珍"),QString::fromLocal8Bit("贞"),QString::fromLocal8Bit("莉"),QString::fromLocal8Bit("桂"),QString::fromLocal8Bit("娣"),QString::fromLocal8Bit("叶"),QString::fromLocal8Bit("璧"),QString::fromLocal8Bit("璐"),QString::fromLocal8Bit("娅"),QString::fromLocal8Bit("琦"),QString::fromLocal8Bit("晶"),QString::fromLocal8Bit("妍"),QString::fromLocal8Bit("茜"),QString::fromLocal8Bit("秋"),QString::fromLocal8Bit("珊"),QString::fromLocal8Bit("莎"),QString::fromLocal8Bit("锦"),QString::fromLocal8Bit("黛"),QString::fromLocal8Bit("青"),QString::fromLocal8Bit("倩"),QString::fromLocal8Bit("婷"),QString::fromLocal8Bit("姣"),QString::fromLocal8Bit("婉"),QString::fromLocal8Bit("娴"),QString::fromLocal8Bit("瑾"),QString::fromLocal8Bit("颖"),QString::fromLocal8Bit("露"),QString::fromLocal8Bit("瑶"),QString::fromLocal8Bit("怡"),QString::fromLocal8Bit("婵"),QString::fromLocal8Bit("雁"),QString::fromLocal8Bit("蓓"),QString::fromLocal8Bit("纨"),QString::fromLocal8Bit("仪"),QString::fromLocal8Bit("荷"),QString::fromLocal8Bit("丹"),QString::fromLocal8Bit("蓉"),QString::fromLocal8Bit("眉"),QString::fromLocal8Bit("君"),QString::fromLocal8Bit("琴"),QString::fromLocal8Bit("蕊"),QString::fromLocal8Bit("薇"),QString::fromLocal8Bit("菁"),QString::fromLocal8Bit("梦"),QString::fromLocal8Bit("岚"),QString::fromLocal8Bit("苑"),QString::fromLocal8Bit("筠"),QString::fromLocal8Bit("柔"),QString::fromLocal8Bit("竹"),QString::fromLocal8Bit("霭"),QString::fromLocal8Bit("凝"),QString::fromLocal8Bit("晓"),QString::fromLocal8Bit("欢"),QString::fromLocal8Bit("霄"),QString::fromLocal8Bit("枫"),QString::fromLocal8Bit("芸"),QString::fromLocal8Bit("菲"),QString::fromLocal8Bit("寒"),QString::fromLocal8Bit("欣"),QString::fromLocal8Bit("滢"),QString::fromLocal8Bit("伊"),QString::fromLocal8Bit("亚"),QString::fromLocal8Bit("宜"),QString::fromLocal8Bit("可"),QString::fromLocal8Bit("姬"),QString::fromLocal8Bit("舒"),QString::fromLocal8Bit("影"),QString::fromLocal8Bit("荔"),QString::fromLocal8Bit("枝"),QString::fromLocal8Bit("思"),QString::fromLocal8Bit("丽"),QString::fromLocal8Bit("秀"),QString::fromLocal8Bit("飘"),QString::fromLocal8Bit("育"),QString::fromLocal8Bit("馥"),QString::fromLocal8Bit("琦"),QString::fromLocal8Bit("晶"),QString::fromLocal8Bit("妍"),QString::fromLocal8Bit("茜"),QString::fromLocal8Bit("秋"),QString::fromLocal8Bit("珊"),QString::fromLocal8Bit("莎"),QString::fromLocal8Bit("锦"),QString::fromLocal8Bit("黛"),QString::fromLocal8Bit("青"),QString::fromLocal8Bit("倩"),QString::fromLocal8Bit("婷"),QString::fromLocal8Bit("宁"),QString::fromLocal8Bit("蓓"),QString::fromLocal8Bit("纨"),QString::fromLocal8Bit("苑"),QString::fromLocal8Bit("婕"),QString::fromLocal8Bit("馨"),QString::fromLocal8Bit("瑗"),QString::fromLocal8Bit("琰"),QString::fromLocal8Bit("韵"),QString::fromLocal8Bit("融"),QString::fromLocal8Bit("园"),QString::fromLocal8Bit("艺"),QString::fromLocal8Bit("咏"),QString::fromLocal8Bit("卿"),QString::fromLocal8Bit("聪"),QString::fromLocal8Bit("澜"),QString::fromLocal8Bit("纯"),QString::fromLocal8Bit("毓"),QString::fromLocal8Bit("悦"),QString::fromLocal8Bit("昭"),QString::fromLocal8Bit("冰"),QString::fromLocal8Bit("爽"),QString::fromLocal8Bit("琬"),QString::fromLocal8Bit("茗"),QString::fromLocal8Bit("羽"),QString::fromLocal8Bit("希")};

        //地区
        QVector<QString>NA5 = {QString::fromLocal8Bit("湖北"),QString::fromLocal8Bit("四川"),QString::fromLocal8Bit("福建"),QString::fromLocal8Bit("甘肃"),QString::fromLocal8Bit("上海"),QString::fromLocal8Bit("新疆"),QString::fromLocal8Bit("东北"),
                               QString::fromLocal8Bit("云南"),QString::fromLocal8Bit("湖南"),QString::fromLocal8Bit("河北"),QString::fromLocal8Bit("河南"),QString::fromLocal8Bit("台湾"),QString::fromLocal8Bit("浙江")};
        //电话号码
        QVector<QString>NA6 = { "174", "177", "180", "181",
                                "130", "131", "132", "145",
                                "155", "156", "166", "171",
                                "175", "176", "185", "186",
                                "134", "135", "136", "137",
                                "138", "139", "147", "148",
                                "150", "151", "152", "157",
                                "158", "159", "172", "178",
                                "182", "183", "184", "187",
                                "178", "188", "198"};
        int sum=0;
        for (int i=8;i>0;i--) {
            int num = (rand()%9)*pow(10,i-1);
            sum += num;
        }
        QString sums = QString::number(sum);

        //性别
        QVector<QString>NA7 = {QString::fromLocal8Bit("男"),QString::fromLocal8Bit("女")};

        QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
        QString m_time = dateTime.toString("yyyy-MM-dd");//格式化时间

        //交易物品
        QVector<QString>NA8 = {QString::fromLocal8Bit("沙发一套"),QString::fromLocal8Bit("床（送三件套）")};

        //是否结清
        QVector<QString>NA9 = {QString::fromLocal8Bit("是"),QString::fromLocal8Bit("否")};

        QString yuan =QString::fromLocal8Bit("元");
        int NARoll = rand() % 444;//单姓
        int NAsRoll = rand() % 59;//复姓
        int NA1Roll = rand() % 140;//男名
        int NA2Roll = rand() % 140;//男名
        int NA3Roll = rand() % 165;//女名
        int NA4Roll = rand() % 165;//女名
        int NA5Roll = rand() % 13;//地区
        int NA6Roll = rand() % 39;//电话
        int NA7Roll = rand() % 2;//性别
        int NA8Roll = rand() % 2;//交易物品
        int NA9Roll = rand() % 2;//是否结清


        // 连接MySQL数据库
        QSqlDatabase db;
        db = QSqlDatabase::database("QMYSQL");
        QSqlQuery query(db);
        // 执行insert语句
        QString str = "insert into bis value("
                +QString::fromLocal8Bit("'")+NA[NARoll]+NAs[NAsRoll]+                   QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+NA5[NA5Roll]+                              QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+NA6[NA6Roll]+sums+                         QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+NA7[NA7Roll]+                              QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+m_time+                                    QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+sums+yuan+                                 QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+NA8[NA8Roll]+                              QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+NA9[NA9Roll]+                              QString::fromLocal8Bit("'")+","
                +QString::fromLocal8Bit("'")+QString::fromLocal8Bit("无")+              QString::fromLocal8Bit("'")+")";
        //        qDebug()<<str;
        query.exec(str);
    }
    // 刷新TableWidget控件
    tableWidget->update();
    return true;
}

void mysqltext::btn_textdata()
{
    textdate(100);
}

bool mysqltext::trueORfalse()
{
    qDebug()<<"true!!!";
    return 1;
}

void mysqltext::into_add_class()
{
    // 获取TableWidget对象
    QTableWidget *tableWidget = ui->tableWidget;
    // 获取当前行数
    int currentRow = tableWidget->rowCount();
    // 插入新行
    tableWidget->insertRow(currentRow);

    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    QString str = dateTime.toString("yyyy-MM-dd");//格式化时间
    // 设置单元格数据
    for (int i=0;i<9;i++) {
        switch (i) {
        case 4: tableWidget->setItem(currentRow, 4, new QTableWidgetItem(str));break;
        default:tableWidget->setItem(currentRow, i, new QTableWidgetItem(QString::fromLocal8Bit("请输入")));break;
        }
    }
    // 刷新TableWidget控件
    tableWidget->update();

}

void mysqltext::btn_save()
{
    // 获取TableWidget对象
    QTableWidget *tableWidget = ui->tableWidget;
    // 获取当前行数
    int currentRows = tableWidget->rowCount()-1;
    // 获取当前选定的行
    int currentRow = tableWidget->currentRow();
    if(currentRow<0){
        return;
    }
    else{
        // 获取该行的数据
        QString save_name = tableWidget->item(currentRow, 0)->text();
        QString save_area = tableWidget->item(currentRow, 1)->text();
        QString save_phone_num = tableWidget->item(currentRow, 2)->text();
        QString save_sex = tableWidget->item(currentRow, 3)->text();
        QString save_Date = tableWidget->item(currentRow, 4)->text();
        QString save_money = tableWidget->item(currentRow, 5)->text();
        QString save_commodity = tableWidget->item(currentRow, 6)->text();
        QString save_Whether_borrow = tableWidget->item(currentRow, 7)->text();
        QString save_remarks = tableWidget->item(currentRow, 8)->text();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromLocal8Bit("保存"), QString::fromLocal8Bit("您确定要保存第%1行吗?客户姓名%2").arg(currentRow+1).arg(save_name),QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // 连接MySQL数据库
            QSqlDatabase db;
            db = QSqlDatabase::database("QMYSQL");
            QSqlQuery query(db);
            // 执行insert语句
            QString str = "insert into bis value("+QString::fromLocal8Bit("'")+save_name+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_area+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_phone_num+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_sex+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_Date+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_money+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_commodity+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_Whether_borrow+QString::fromLocal8Bit("'")+","
                    +QString::fromLocal8Bit("'")+save_remarks+QString::fromLocal8Bit("'")+")";
            qDebug()<<str;
            query.exec(str);
            // 刷新TableWidget控件
            tableWidget->update();
        }
        else{
            // 刷新TableWidget控件
            tableWidget->update();
            return;
        }
    }
}

void mysqltext::into_delete_class()
{
    // 获取TableWidget对象5
    QTableWidget *tableWidget = ui->tableWidget;
    // 获取当前选定的行
    int currentRow = tableWidget->currentRow();
    // 如果没有选定行，则获取最后一行
    if (currentRow == -1) {
        currentRow = tableWidget->rowCount() - 1;
    }
    // 获取该行的数据
    QString name = tableWidget->item(currentRow, 0)->text();
    QString area = tableWidget->item(currentRow, 1)->text();
    QString phone_num = tableWidget->item(currentRow, 2)->text();
    QString sex = tableWidget->item(currentRow, 3)->text();
    QString Date = tableWidget->item(currentRow, 4)->text();
    QString money = tableWidget->item(currentRow, 5)->text();
    QString commodity = tableWidget->item(currentRow, 6)->text();
    QString Whether_borrow = tableWidget->item(currentRow, 7)->text();
    QString remarks = tableWidget->item(currentRow, 8)->text();
    qDebug()<<name;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromLocal8Bit("删除"), QString::fromLocal8Bit("您确定要删除第%1行吗?").arg(currentRow+1),QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户选择了“是”，执行删除操作
        // 删除选定的行
        tableWidget->removeRow(currentRow);
        // 连接MySQL数据库
        QSqlDatabase db;
        db = QSqlDatabase::database("QMYSQL");
        QSqlQuery query(db);
        // 执行DELETE语句
        //delete from bis where name='连接' and sex='男' and phone_num='1231111111' and area='湖北' and Date='20110807' and money='123' and commodity='沙发一件套' and Whether_borrow='已结清' and remarks='无';
        QString str = "DELETE FROM bis WHERE name="+QString::fromLocal8Bit("'")+name+QString::fromLocal8Bit("'")+
                " AND area="+QString::fromLocal8Bit("'")+area+QString::fromLocal8Bit("'")+
                " AND phone_num="+QString::fromLocal8Bit("'")+phone_num+QString::fromLocal8Bit("'")+
                " AND sex="+QString::fromLocal8Bit("'")+sex+QString::fromLocal8Bit("'")+
                " AND Date="+QString::fromLocal8Bit("'")+Date+QString::fromLocal8Bit("'")+
                " AND money="+QString::fromLocal8Bit("'")+money+QString::fromLocal8Bit("'")+
                " AND commodity="+QString::fromLocal8Bit("'")+commodity+QString::fromLocal8Bit("'")+
                " AND Whether_borrow="+QString::fromLocal8Bit("'")+Whether_borrow+QString::fromLocal8Bit("'")+
                " AND remarks="+QString::fromLocal8Bit("'")+remarks+QString::fromLocal8Bit("'");
        qDebug()<<str;
        query.exec(str);
        // 刷新TableWidget控件
        tableWidget->update();
    } else {
        // 用户选择了“否”，取消删除操作
        // 刷新TableWidget控件
        //tableWidget->update();
        return;
    }

}

void mysqltext::search()
{
    QSqlDatabase db;
    db = QSqlDatabase::database("QMYSQL");
    QSqlQuery query(db);
    if(ui->cmbox_col->currentIndex() == 0) {
        //QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请选择查询类型!"), QString::fromLocal8Bit("确认"));
        QString str = "select * from bis;";//查询语句
        query.prepare(str);//准备
        int i=0;
        if(query.exec())
        {
            //依次读取查询到的记录
            while(query.next())
            {
                ui->tableWidget->setRowCount(i+1);//设置表格行数
                for (int s=0;s<9;s++) {
                    ui->tableWidget->setItem(i,s,new QTableWidgetItem(query.value(s).toString()));
                    ui->tableWidget->item(i,s)->setTextAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
                }
                i++;
            }
        }

    } else {
        int index = ui->cmbox_col->currentIndex();
        QString str1, str2;
        switch (index) {
        case 1:
            str1 = "name";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 2:
            str1 = "area";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;

        case 3:
            str1 = "phone_num";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 4:
            str1 = "sex";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 5:
            str1 = "Date";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 6:
            str1 = "money";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 7:
            str1 = "commodity";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 8:
            str1 = "Whether_borrow";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        case 9:
            str1 = "remarks";
            str2 = QString::fromLocal8Bit("'") + ui->le_keyword->text() + QString::fromLocal8Bit("'");
            break;
        default:
            break;
        }

        int col = 9;
        int row;
        QString get_row = "select count(name) from bis where "+ str1 + QString::fromLocal8Bit(" = ") + str2;   //获取行数
        qDebug()<<get_row;
        query.exec(get_row);
        if(query.first()){
            row = query.value(QString::fromLocal8Bit("count(name)")).toInt();
            ui->tableWidget->setRowCount(row);
        }
        if (row != 0) {     //如果查询结果不为空
            ui->tableWidget->setColumnCount(col);
            QStringList header; //表头写入表格
            header << QString::fromLocal8Bit("姓名") << QString::fromLocal8Bit("地区") << QString::fromLocal8Bit("电话号码") << QString::fromLocal8Bit("性别")
                   << QString::fromLocal8Bit("交易日期")<< QString::fromLocal8Bit("交易金额")<< QString::fromLocal8Bit("交易物品")<< QString::fromLocal8Bit("是否结款")
                   << QString::fromLocal8Bit("备注");
            ui->tableWidget->setHorizontalHeaderLabels(header);
            ui->tableWidget->horizontalHeader()->setStretchLastSection(true);   //自动调整宽度

            QString str = "select * from bis where "+ str1 + QString::fromLocal8Bit(" = ") + str2;
            query.exec(str);

            for (int i = 0; query.next(); i++) {
                for (int j = 0; j < col; j++) {
                    ui->tableWidget->setItem( i, j, new QTableWidgetItem(query.value(j).toString()));
                    ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
                }
            }
        } else
            QMessageBox::information(this, QString::fromLocal8Bit("查询结果"), QString::fromLocal8Bit("未找到相关信息!请更换查询内容后再次尝试!"), QString::fromLocal8Bit("确认"));
    }
    ui->le_keyword->clear();
}

void mysqltext::btn_return()
{
    this->close();
}


void mysqltext::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    //设置编辑模式
    if (Qt::Checked)
        //双击或获取焦点后单击，进入编辑状态
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    else
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //不允许编辑
}
