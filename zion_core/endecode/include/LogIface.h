
#include <sys/types.h>
#include <sys/stat.h>
#ifdef WIN32
#include <conio.h>
#endif

#ifndef _LOGIFACE_H_
#define _LOGIFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_BUF_LENG		10240			/// < Max size for log buffer

typedef signed int	LOG4RESULT;
typedef	signed int	LOG4LONG;
//typedef signed int	INT32;

/**
@remarks logger handler Ÿ��
*/
typedef void* FrLogHandle;

enum {
	e_LOG_FATAL = 0x01,	
	e_LOG_ASSERT = 0x02,
	e_LOG_ERROR = 0x04,	
	e_LOG_WARN = 0x08,	
	e_LOG_INFO = 0x10,	
	e_LOG_DEBUG = 0x20,	
	e_LOG_TRACE = 0x40
};


/**
@remarks global variable for log handle
*/
extern FrLogHandle	gLogHandle;


/**
@remarks �ý��� ������ ����ϴ� ����
*/
#define FDR_LOG_FATAL	(char*)__FILE__, __LINE__, e_LOG_FATAL

/**
@remarks Application ������ ����ϴ� ����
*/
#define FDR_LOG_ERROR	(char*)__FILE__, __LINE__, e_LOG_ERROR

/**
@remarks Application ��� ����� ������ ����ϴ� ����
*/
#define FDR_LOG_WARN	(char*)__FILE__, __LINE__, e_LOG_WARN

/**
@remarks Application�� ���� ���¸� ������ ����ϴ� ����, ��� �� ���� ���¸� ��ȸ�� �� ���
*/
#define FDR_LOG_INFO	(char*)__FILE__, __LINE__, e_LOG_INFO

/**
@remarks Application ����� �뵵�� ���Ǵ� ����, �ּ����� ����� ������ ����� �� ���
*/
#define FDR_LOG_DEBUG	(char*)__FILE__, __LINE__, e_LOG_DEBUG

/**
@remarks Application�� ���� ���� ������ ����� �� �� ���Ǵ� ����, �ſ� ���� ������ ����̰ų� ������ �����ϱ� ����� ������ ��� ���
*/
#define FDR_LOG_TRACE	(char*)__FILE__, __LINE__, e_LOG_TRACE

/**
######################################################################
#%p  debug, info, warn, error, fatal ���� priority �� ��µȴ�.
#%m  �α׳����� ��µ˴ϴ�
#%d  �α� �̺�Ʈ�� �߻��� �ð��� ����մϴ�.
#  ������ %d{HH:mm:ss, SSS}, %d{yyyy MMM dd HH:mm:ss, SSS}���� ���·� ����ϸ� SimpleDateFormat�� ���� �������� �ϸ� �ȴ�
#%t  �α��̺�Ʈ�� �߻��� �������� �̸��� ����մϴ�.
#%%  % ǥ�ø� ����ϱ� ���� ����Ѵ�.
#%n  �÷��� �������� ���๮�ڰ� ��µȴ�. \r\n �Ǵ� \n �ϰ��̴�.
#%c  ī�װ��� ǥ���մϴ�
#  ��) ī�װ��� a.b.c ó�� �Ǿ��ִٸ� %c{2}�� b.c�� ��µ˴ϴ�.
#%C  Ŭ�������� �����մϴ�.
#  ��)Ŭ���������� org.apache.xyz.SomeClass ó�� �Ǿ��ִٸ� %C{2}�� xyz.SomeClass �� ��µ˴ϴ�
#%F  �α��� �߻��� ���α׷� ���ϸ��� ��Ÿ���ϴ�.
#%l  �α��� �߻��� caller�� ������ ��Ÿ���ϴ�
#%L  �α��� �߻��� caller�� ���μ��� ��Ÿ���ϴ�
#%M  �α��� �߻��� method �̸��� ��Ÿ���ϴ�.
#%r  ���ø����̼� ���� ���� ���� �α��� �߻��� ������ �ð�(milliseconds)
#%x  �α��� �߻��� thread�� ���õ� NDC(nested diagnostic context)�� ����մϴ�.
#%X  �α��� �߻��� thread�� ���õ� MDC(mapped diagnostic context)�� ����մϴ�.
#######################################################################

"[%d{yyyy.MM.dd HH:mm:ss,SSS}](%-14F,%4L)[%p] %m%n";  ///< Basic log pattern
**/


/**
@brief Open the console logger
@remarks ������� console�� ����ϴ� logger handler�� �����Ѵ�.
@param phHandle logger handler
@param szUnitName logger �ĺ��� (�� �α� ���� Unique)
@param szPattern Pattern string (���� NULL�̸� default pattern ���)
@return ó�� ��� �ڵ�
*/
LOG4RESULT FrLogConsoleOpen(FrLogHandle* phHandle, char *szUnitName, char *szPattern);

/**
@brief Open the file logger
@remarks ������� ������ ����ϴ� logger handler�� �����Ѵ�.
@param phHandle logger handler
@param szUnitName logger �ĺ��� (�� �α� ���� Unique)
@param szLogFilename �α� ���� �̸� (full path)
@param szPattern Pattern string (���� NULL�̸� default pattern ���)
@return ó�� ��� �ڵ�
*/
LOG4RESULT FrLogFileOpen(FrLogHandle* phHandle, char *szUnitName, char *szLogFilename, char *szPattern, LOG4LONG nAppend);

/**
@brief Open the rolling file logger
@remarks ������� ������ ����ϴ� logger handler�� �����Ѵ�. �̶� ������ ������ ���ǿ� ���� ��� �����Ͽ� rolling�ȴ�.
@param phHandle logger handler
@param szUnitName logger �ĺ��� (�� �α� ���� Unique)
@param szLogFilename �α� ���� �̸� (full path)
@param szPattern Pattern string (���� NULL�̸� default pattern ���)
@param nMaxFileSize ������Ϸ� roll over �Ǵ� ���� ������
@param nIndexCnt wraparound �Ǵ� ��� ������ �ִ� ����
@return ó�� ��� �ڵ�
*/
LOG4RESULT FrLogRollingFileOpen(FrLogHandle* phHandle, char *szUnitName, char *szLogFilename, char *szPattern, LOG4LONG nMaxFileSize, LOG4LONG nIndexCnt);

/**
@brief Open the daily rolling file logger
@remarks ������� ������ ����ϴ� logger handler�� �����Ѵ�. �̶� daily�� ��� �����Ͽ� rolling�ȴ�.
@param phHandle logger handler
@param szUnitName logger �ĺ��� (�� �α� ���� Unique)
@param szLogFilename �α� ���� �̸� (full path)
@param szPattern Pattern string (���� NULL�̸� default pattern ���)
@return ó�� ��� �ڵ�
*/
LOG4RESULT FrLogDailyRollingFileOpen(FrLogHandle* phHandle, char *szUnitName, char *szLogFilename, char *szPattern);

/**
@brief Open the external configured logger
@remarks �ܺ� �������Ϸ� ���� ���� ������ �����ϴ� logger handler�� �����Ѵ�.
@param phHandle logger handler
@param szUnitName logger �ĺ��� (�� �α� ���� Unique)
@param szConfigFile ���� ���� ���� �̸�
@return ó�� ��� �ڵ�
*/
LOG4RESULT FrLogOpenFromCFGFile(FrLogHandle* phHandle, char *szUnitName, char *szConfigFile);

/**
@brief Close the logger
@remarks logger handle�� �����Ѵ�.
@param phHandle logger handle
*/
void FrLogClose(FrLogHandle phHandle);

/**
@brief Select the log level
@remarks �α� ������ �����Ѵ�.
@param phHandle logger handle
@param log_level ��µ� �α��� �ּ� ���� (������ ���� �̻��� ������ ��� ���)
*/
LOG4RESULT FrLogSetLevel(FrLogHandle phHandle, int log_level);

/**
@brief Get the logger
@remarks ������ Unit Name�� logger ��ü�� ���´�.
@param phHandle logger handler
@param szUnitName logger �ĺ��� (�� �α� ���� Unique)
@return ó�� ��� �ڵ�
*/
LOG4RESULT FrGetLogger(FrLogHandle* phHandle, char *szUnitName);

/**
@brief Print the log message
@remarks ������ ������ �޽����� ������ ������ �α׷� ����Ѵ�. ��� ����� Open�Լ��� �����ǰų� �������Ϸ� �����ȴ�.
@param phHandle logger handle
@param file_name �α� ��� ��û�� �ҽ� ���� �̸� (full path)
@param file_line �α� ��� ��û�� �ҽ� ������ ����
@param log_level log level (�α� ������ ���� : LOG_FATAL, LOG_ERROR, LOG_WARN, LOG_INFO, LOG_TRACE, LOG_DEBUG)
@param format ��µ� �α� ���� (printf�� ������ ����)
*/
void FrLogPrn(FrLogHandle phHandle, char* file_name, int file_line, int log_level , const char *format, ... );

#ifdef __cplusplus
}
#endif

#endif //_LOGIFACE_H_
