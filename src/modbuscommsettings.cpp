#include "modbuscommsettings.h"
#include "QsLog.h"

ModbusCommSettings::ModbusCommSettings(const QString &fileName, Format format , QObject *parent)
    : QSettings(fileName, format, parent)
{
    this->loadSettings();
}

void  ModbusCommSettings::loadSettings()
{

    load(this);

}

void  ModbusCommSettings::saveSettings()
{

    save(this);

}

QString  ModbusCommSettings::TCPPort()
{
    return m_TCPPort;
}

void ModbusCommSettings::setTCPPort(QString tcpPort)
{
    m_TCPPort = tcpPort;
}

void ModbusCommSettings::setSlaveIP(QString IP)
{
    m_slaveIP = IP;
}

QString  ModbusCommSettings::slaveIP()
{
    return m_slaveIP;
}

QString  ModbusCommSettings::serialDev()
{
    return m_serialDev;
}

QString  ModbusCommSettings::serialPort()
{
    return m_serialPort;
}

QString  ModbusCommSettings::serialPortName()
{
    return m_serialPortName;
}

void ModbusCommSettings::setSerialPort(QString serialPort, QString serialDev)
{
int serialPortNo;

    m_serialDev = serialDev;
    m_serialPort = serialPort;
    serialPortNo = serialPort.toInt();
    #ifdef Q_OS_WIN32
    if (serialPortNo > 9)
        m_serialPortName = "\\\\.\\COM" + serialPort;
    else
        m_serialPortName = "COM" + serialPort;
    #else
        m_serialPortName = serialDev;
        m_serialPortName += QStringLiteral("%1").arg(serialPort.toInt() - 1);
    #endif
}

QString  ModbusCommSettings::baud()
{
    return m_baud;
}

void ModbusCommSettings::setBaud(QString baud)
{
    m_baud = baud;
}

QString  ModbusCommSettings::dataBits()
{
    return m_dataBits;
}

void ModbusCommSettings::setDataBits(QString dataBits)
{
    m_dataBits = dataBits;
}

QString  ModbusCommSettings::stopBits()
{
    return m_stopBits;
}

void ModbusCommSettings::setStopBits(QString stopBits)
{
    m_stopBits = stopBits;
}

QString  ModbusCommSettings::parity()
{
    return m_parity;
}

void ModbusCommSettings::setParity(QString parity)
{
    m_parity = parity;
}

QString  ModbusCommSettings::RTS()
{
    return m_RTS;
}

void ModbusCommSettings::setRTS(QString RTS)
{
    m_RTS = RTS;
}

QString  ModbusCommSettings::maxNoOfLines()
{
    return m_maxNoOfLines;
}

void ModbusCommSettings::setMaxNoOfLines(QString maxNoOfLines)
{
    m_maxNoOfLines = maxNoOfLines;
}

QString  ModbusCommSettings::baseAddr()
{
    return m_baseAddr;
}

void ModbusCommSettings::setBaseAddr(QString baseAddr)
{
    m_baseAddr = baseAddr;
}

QString  ModbusCommSettings::timeOut()
{
    return m_timeOut;
}

void ModbusCommSettings::setTimeOut(QString timeOut)
{
    m_timeOut = timeOut;
}

int  ModbusCommSettings::endian()
{
    return m_endian;
}

void ModbusCommSettings::setEndian(int endian)
{
    m_endian = endian;
}

int  ModbusCommSettings::loggingLevel()
{
    return m_loggingLevel;
}

bool  ModbusCommSettings::readOutputsBeforeWrite()
{
    return m_readOutputsBeforeWrite;
}

int ModbusCommSettings::modbusMode()
{
    return m_modbusMode;
}

void ModbusCommSettings::setModbusMode(int modbusMode)
{
    m_modbusMode = modbusMode;
}

int ModbusCommSettings::slaveID()
{
    return m_slaveID;
}

void ModbusCommSettings::setSlaveID(int slaveID)
{
    m_slaveID = slaveID;
}

int ModbusCommSettings::scanRate()
{
    return m_scanRate;
}

void ModbusCommSettings::setScanRate(int scanRate)
{
    m_scanRate = scanRate;
}

int ModbusCommSettings::functionCode()
{
    return m_functionCode;
}

void ModbusCommSettings::setFunctionCode(int functionCode)
{
    m_functionCode = functionCode;
}

int ModbusCommSettings::startAddr()
{
    return m_startAddr;
}

void ModbusCommSettings::setStartAddr(int startAddr)
{
    m_startAddr = startAddr;
}

int ModbusCommSettings::noOfRegs()
{
    return m_noOfRegs;
}

void ModbusCommSettings::setNoOfRegs(int noOfRegs)
{
    m_noOfRegs = noOfRegs;
}

int ModbusCommSettings::frmt()
{
    return m_frmt;
}

void ModbusCommSettings::setFrmt(int frmt)
{
    m_frmt = frmt;
}

int ModbusCommSettings::floatPrecision()
{
    return m_floatPrecision;
}

void ModbusCommSettings::setfloatPrecision(int precision)
{
    m_floatPrecision = precision;
}

void ModbusCommSettings::loadSession(QString fName)
{

    QLOG_INFO()<<  "Load session config from file " << fName;
    QSettings m_save_session(fName, QSettings::IniFormat, this);
    load(&m_save_session);

}

void ModbusCommSettings::saveSession(QString fName)
{

    QLOG_INFO()<<  "Save session config to file " << fName;
    QSettings m_save_session(fName, QSettings::IniFormat, this);
    save(&m_save_session);

}

void ModbusCommSettings::load(QSettings *s)
{

    if (s->value("TCP/TCPPort").isNull())
        m_TCPPort = "502";
    else
        m_TCPPort = s->value("TCP/TCPPort").toString();

    if (s->value("TCP/SlaveIP").isNull())
        m_slaveIP = "127.000.000.001";
    else
        m_slaveIP = s->value("TCP/SlaveIP").toString();

    if (s->value("RTU/SerialDev").isNull())
        #ifdef Q_OS_WIN32
            m_serialDev = "COM";
        #else
            m_serialDev = "/dev/ttyS";
        #endif
    else
        #ifdef Q_OS_WIN32
            m_serialDev = "COM";
        #else
            m_serialDev = s->value("RTU/SerialDev").toString();
        #endif
    if (s->value("RTU/SerialPort").isNull())
    {
        m_serialPort = "1";
        #ifdef Q_OS_WIN32
            m_serialPortName = "COM" + m_serialPort;
        #else
            m_serialPortName = m_serialDev;
            m_serialPortName += QStringLiteral("%1").arg(m_serialPort.toInt() - 1);
        #endif
    }
    else {
        m_serialPort = s->value("RTU/SerialPort").toString();
        m_serialPortName = s->value("RTU/SerialPortName").toString();
    }

    if (s->value("RTU/Baud").isNull())
        m_baud = "9600";
    else
        m_baud = s->value("RTU/Baud").toString();

    if (s->value("RTU/DataBits").isNull())
        m_dataBits = "8";
    else
        m_dataBits = s->value("RTU/DataBits").toString();

    if (s->value("RTU/StopBits").isNull())
        m_stopBits = "1";
    else
        m_stopBits = s->value("RTU/StopBits").toString();

    if (s->value("RTU/Parity").isNull())
        m_parity = "N";
    else
        m_parity = s->value("RTU/Parity").toString();

    if (s->value("RTU/RTS").isNull())
        #ifdef Q_OS_WIN32
            m_RTS = "Disable";
        #else
            m_RTS = "None";
        #endif
    else
        m_RTS = s->value("RTU/RTS").toString();

    if (s->value("Var/MaxNoOfLines").toInt() == 0 ||
            s->value("Var/MaxNoOfLines").isNull())
        m_maxNoOfLines = "60";
    else
        m_maxNoOfLines = s->value("Var/MaxNoOfLines").toString();

    if (s->value("Var/BaseAddr").isNull())
        m_baseAddr = "1";
    else
        m_baseAddr = s->value("Var/BaseAddr").toString();

    if (s->value("Var/TimeOut").isNull())
        m_timeOut = "0";
    else
        m_timeOut = s->value("Var/TimeOut").toString();

    if (s->value("Var/LoggingLevel").isNull())
        m_loggingLevel = 3; //warning level
    else
        m_loggingLevel = s->value("Var/LoggingLevel").toInt();

    if (s->value("Var/ReadOutputsBeforeWrite").isNull())
        m_readOutputsBeforeWrite = true;
    else
        m_readOutputsBeforeWrite = s->value("Var/ReadOutputsBeforeWrite").toBool();

    if (s->value("Var/Endian").isNull())
        m_endian = 0;
    else
        m_endian = s->value("Var/Endian").toInt();

    if (s->value("Session/ModBusMode").isNull())
        m_modbusMode = 0; //RTU
    else
        m_modbusMode = s->value("Session/ModBusMode").toInt();

    if (s->value("Session/SlaveID").isNull())
        m_slaveID = 1;
    else
        m_slaveID = s->value("Session/SlaveID").toInt();

    if (s->value("Session/ScanRate").isNull())
        m_scanRate = 1000;
    else
        m_scanRate = s->value("Session/ScanRate").toInt();

    if (s->value("Session/FunctionCode").isNull())
        m_functionCode = 0; //FC1 : Read Coils
    else
        m_functionCode = s->value("Session/FunctionCode").toInt();

    if (s->value("Session/StartAddr").isNull())
        m_startAddr = 0;
    else
        m_startAddr = s->value("Session/StartAddr").toInt();

    if (s->value("Session/NoOfRegs").isNull())
        m_noOfRegs = 0;
    else
        m_noOfRegs = s->value("Session/NoOfRegs").toInt();

    if (s->value("Session/Format").isNull())
        m_frmt = 1; //Dec
    else
        m_frmt = s->value("Session/Format").toInt();

    if (s->value("Session/FloatPrecision").isNull())
        m_floatPrecision = 3;
    else
        m_floatPrecision = s->value("Session/FloatPrecision").toInt();

}

void ModbusCommSettings::save(QSettings *s)
{

    s->setValue("TCP/TCPPort",m_TCPPort);
    s->setValue("TCP/SlaveIP",m_slaveIP);
    s->setValue("RTU/SerialDev",m_serialDev);
    s->setValue("RTU/SerialPort",m_serialPort);
    s->setValue("RTU/SerialPortName",m_serialPortName);
    s->setValue("RTU/Baud",m_baud);
    s->setValue("RTU/DataBits",m_dataBits);
    s->setValue("RTU/StopBits",m_stopBits);
    s->setValue("RTU/Parity",m_parity);
    s->setValue("RTU/RTS",m_RTS);
    s->setValue("Var/MaxNoOfLines",m_maxNoOfLines);
    s->setValue("Var/BaseAddr",m_baseAddr);
    s->setValue("Var/TimeOut",m_timeOut);
    s->setValue("Var/LoggingLevel",m_loggingLevel);
    s->setValue("Var/ReadOutputsBeforeWrite",m_readOutputsBeforeWrite);
    s->setValue("Var/Endian",m_endian);
    s->setValue("Session/ModBusMode",m_modbusMode);
    s->setValue("Session/SlaveID",m_slaveID);
    s->setValue("Session/ScanRate",m_scanRate);
    s->setValue("Session/FunctionCode",m_functionCode);
    s->setValue("Session/StartAddr",m_startAddr);
    s->setValue("Session/NoOfRegs",m_noOfRegs);
    s->setValue("Session/Format",m_frmt);
    s->setValue("Session/FloatPrecision",m_floatPrecision);

}
