
#ifndef _MEDIAERROR_H_
#define _MEDIAERROR_H_

#define FRSUCCEEDED(x)					(!((x)&0x80000000))
#define FRFAILED(x)						((x)&0x80000000)

#define FR_OK							0x00000000
#define FR_FAIL							0x80000000

///////////////////////////////////////////////////////////////////////////
// Base error code
///////////////////////////////////////////////////////////////////////////
#define	COMMON_ERR_BASE					(FR_FAIL + 0x00000000)			// common

#define	HTTP_ERR_BASE					(FR_FAIL + 0x01000000)			// HTTP Base Error

#define FILTERGRAPH_ERR_BASE			(FR_FAIL + 0x00600000)			// filter graph
#define	SRCFILTER_ERR_BASE				(FR_FAIL + 0x00610000)			// source filter
#define	ADECFILTER_ERR_BASE				(FR_FAIL + 0x00620000)			// audio decoder filter
#define	VDECFILTER_ERR_BASE				(FR_FAIL + 0x00630000)			// video decoder filter
#define	AENCFILTER_ERR_BASE				(FR_FAIL + 0x00640000)			// audio encoder filter
#define	VENCFILTER_ERR_BASE				(FR_FAIL + 0x00650000)			// video encoder filter
#define	ARENFILTER_ERR_BASE				(FR_FAIL + 0x00660000)			// audio render filter
#define	VRENFILTER_ERR_BASE				(FR_FAIL + 0x00670000)			// video render filter

///////////////////////////////////////////////////////////////////////////
// common error code
///////////////////////////////////////////////////////////////////////////
#define	COMMON_ERR_MEM					(COMMON_ERR_BASE + 0x01)		// �޸𸮰� �����մϴ�.
#define COMMON_ERR_THREAD				(COMMON_ERR_BASE + 0x02)		// �����带 ������ �� �����ϴ�.
#define	COMMON_ERR_SYSTEM				(COMMON_ERR_BASE + 0x03)		// �ý��� �ʱ�ȭ�� �����߽��ϴ�.
#define	COMMON_ERR_NETWORK				(COMMON_ERR_BASE + 0x04)		// ��Ʈ��ũ System�� Fail
#define COMMON_ERR_CANCEL				(COMMON_ERR_BASE + 0x05)		// �ܺο��� ���ڵ� ��� ��û
#define COMMON_ERR_NULLPOINTER			(COMMON_ERR_BASE + 0x06)		// NULL ������ �Է�
#define	COMMON_ERR_INVALIDINPUT			(COMMON_ERR_BASE + 0x07)		// �������� �ʴ� �Է°� ����

#define	COMMON_ERR_FOPEN				(COMMON_ERR_BASE + 0x10)		// ������ ã�� ���� �����ϴ�.
#define	COMMON_ERR_FCREATE				(COMMON_ERR_BASE + 0x11)		// ������ ���� �� ���� �����ϴ�.
#define	COMMON_ERR_URL					(COMMON_ERR_BASE + 0x12)		// �������� �ʴ� URL �����Դϴ�.
#define COMMON_ERR_ENCRYPTION			(COMMON_ERR_BASE + 0x13)		// Encryption�� �������Դϴ�.
#define COMMON_ERR_EXPIRED_DATA			(COMMON_ERR_BASE + 0x14)		// ��ȿ�Ⱓ�� ����Ǿ����ϴ�.
#define	COMMON_ERR_NODATA				(COMMON_ERR_BASE + 0x15)		// �����Ͱ� ����.
#define	COMMON_ERR_ENDOFDATA			(COMMON_ERR_BASE + 0x16)		// �������� ���̴�.
#define	COMMON_ERR_NEEDDATA				(COMMON_ERR_BASE + 0x17)		// �����Ͱ� �� �ʿ��ϴ�.
#define	COMMON_ERR_NONEEDDATA			(COMMON_ERR_BASE + 0x18)		// �����Ͱ� �� �ʿ����.
#define	COMMON_ERR_WAITDATA				(COMMON_ERR_BASE + 0x19)		// �����͸� ��ٷ��� �Ѵ�.
#define	COMMON_ERR_NOMEDIA				(COMMON_ERR_BASE + 0x1A)		// �ش� �̵� ����.
#define	COMMON_ERR_FUNCTION				(COMMON_ERR_BASE + 0x1B)		// �������� �ʴ� ����Դϴ�.
#define	COMMON_ERR_INVALID_RANGE		(COMMON_ERR_BASE + 0x1C)		// ���� �׼����� �����߽��ϴ�.
#define	COMMON_ERR_FREAD				(COMMON_ERR_BASE + 0x1D)		// �����б⸦ �����Ͽ����ϴ�.
#define COMMON_ERR_LIMITDATA            (COMMON_ERR_BASE + 0x1E)        // ���ѵ� ����� �����Ͽ����ϴ�.
#define	COMMON_ERR_MUSTNOTSUPPORT		(COMMON_ERR_BASE + 0x101)		// �����ؼ��� �ȵǴ� ����
#define COMMON_ERR_NOTCAPABLE			(COMMON_ERR_BASE + 0x102)		// �������� ���ϴ� ���� (���� ũ�⳪ ���� ���� ����)
#define	COMMON_ERR_PAUSEDATA			(COMMON_ERR_BASE + 0x103)		// �������� ���ϴ� ���� (���� ũ�⳪ ���� ���� ����)

#define	COMMON_ERR_FILETYPE				(COMMON_ERR_BASE + 0x200)		// �������� �ʴ� ���� �����Դϴ�.
#define	COMMON_ERR_STREAMSYNTAX			(COMMON_ERR_BASE + 0x201)		// ��Ʈ�� ������ �߻��Ͽ����ϴ�.
#define	COMMON_ERR_MEDIAPARAM			(COMMON_ERR_BASE + 0x202)		// �߸��� �̵�� �Ķ���� �����Դϴ�.
#define	COMMON_ERR_AUDIOCODEC			(COMMON_ERR_BASE + 0x203)		// �������� �ʴ� ����� �����Դϴ�.
#define	COMMON_ERR_VIDEOCODEC			(COMMON_ERR_BASE + 0x204)		// �������� �ʴ� ���� �����Դϴ�.
#define	COMMON_ERR_TEXTCODEC			(COMMON_ERR_BASE + 0x205)		// �������� �ʴ� �ؽ�Ʈ �����Դϴ�.
#define	COMMON_ERR_AUDIODEC				(COMMON_ERR_BASE + 0x206)		// ����� ���ڴ��� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_VIDEODEC				(COMMON_ERR_BASE + 0x207)		// ���� ���ڴ��� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_TEXTDEC				(COMMON_ERR_BASE + 0x208)		// �ؽ�Ʈ ���ڴ��� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_AUDIOENC				(COMMON_ERR_BASE + 0x209)		// ����� ���ڴ��� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_VIDEOENC				(COMMON_ERR_BASE + 0x20A)		// ���� ���ڴ��� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_TEXTENC				(COMMON_ERR_BASE + 0x20B)		// �ؽ�Ʈ ���ڴ��� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_AUDIODEVIN			(COMMON_ERR_BASE + 0x20C)		// ����� �Է���ġ�� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_VIDEODEVIN			(COMMON_ERR_BASE + 0x20D)		// ���� �Է���ġ�� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_AUDIODEVOUT			(COMMON_ERR_BASE + 0x20E)		// ����� �����ġ�� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_VIDEODEVOUT			(COMMON_ERR_BASE + 0x20F)		// ���� �����ġ�� �ʱ�ȭ�ϱ� ���߽��ϴ�.
#define	COMMON_ERR_VIDEOOUTFORMAT		(COMMON_ERR_BASE + 0x210)		// �������� �ʴ� ���� ��� �����Դϴ�.	
#define	COMMON_ERR_AUDIODEC_FRAME		(COMMON_ERR_BASE + 0x211)		// ����� ������ ���ڵ� ����
#define	COMMON_ERR_VIDEODEC_FRAME		(COMMON_ERR_BASE + 0x212)		// ���� ������ ���ڵ� ����
#define	COMMON_ERR_DECODE_BLOCKING		(COMMON_ERR_BASE + 0x213)		// ���ڵ� ���� Ȥ�� ���ڴ� ��ŷ
#define	COMMON_ERR_ENCODE_BLOCKING		(COMMON_ERR_BASE + 0x214)		// ���ڵ� ���� Ȥ�� ���ڴ� ��ŷ
#define	COMMON_ERR_TEXTDEVOUT			(COMMON_ERR_BASE + 0x215)		// �ؽ�Ʈ �����ġ�� �ʱ�ȭ�ϱ� ���߽��ϴ�.

#define	COMMON_ERR_SOCKET				(COMMON_ERR_BASE + 0x30)		// ���� ������ �߻��߽��ϴ�.
#define	COMMON_ERR_INVALID_PROTOCOL		(COMMON_ERR_BASE + 0x31)		// �������� ������ �߻��Ͽ����ϴ�.
#define	COMMON_ERR_SEND					(COMMON_ERR_BASE + 0x32)		// Send ����
#define	COMMON_ERR_RECV					(COMMON_ERR_BASE + 0x33)		// Recv ����
#define	COMMON_ERR_TIMEOUT				(COMMON_ERR_BASE + 0x34)		// �ð��� �ʰ��Ͽ����ϴ�.
#define	COMMON_ERR_SERVER				(COMMON_ERR_BASE + 0x35)		// �������� ������ �߻��߽��ϴ�.
#define	COMMON_ERR_SVR_CONNECT			(COMMON_ERR_BASE + 0x36)		// ������ ������ ���� �����ϴ�.
#define	COMMON_ERR_SVR_DISCONNECT		(COMMON_ERR_BASE + 0x37)		// �������� ������ ���������ϴ�.
#define	COMMON_ERR_SVR_NORESPONSE		(COMMON_ERR_BASE + 0x38)		// �����κ��� ������ �����ϴ�.
#define	COMMON_ERR_SVR_NODATA			(COMMON_ERR_BASE + 0x39)		// �����κ��� ���۵Ǵ� �����Ͱ� �����ϴ�.
#define	COMMON_ERR_CLIENT				(COMMON_ERR_BASE + 0x3A)		// �߸��� ��û�� �õ��Ͽ����ϴ�.
#define	COMMON_ERR_CLI_ACCEPT			(COMMON_ERR_BASE + 0x3B)		// �ܸ��� ���� ��û�� �źεǾ����ϴ�.
#define	COMMON_ERR_CLI_DISCONNECT		(COMMON_ERR_BASE + 0x3C)		// �ܸ����� ������ ���������ϴ�.
#define	COMMON_ERR_CLI_NOREQUEST		(COMMON_ERR_BASE + 0x3D)		// �ܸ��κ��� ��û�� �����ϴ�.
#define	COMMON_ERR_NOTMATCH_SSRC		(COMMON_ERR_BASE + 0x3E)		// SSRC�� ��ġ���� �ʴ´�.
#define	COMMON_ERR_NOTMATCH_SCID		(COMMON_ERR_BASE + 0x3F)		// SID CID�� ��ġ���� �ʴ´�.
#define	COMMON_ERR_UNSUPPORT_TRASNPORT	(COMMON_ERR_BASE + 0x40)		// Unsupported transport.
#define	COMMON_ERR_RECV_ZERO			(COMMON_ERR_BASE + 0x41)		// recv size is Zero..

//HTTP
#define COMMON_ERR_REDIRECT				(COMMON_ERR_BASE + 0x4E)		// �ű� URL�� ��ȯ�մϴ�. - Naver UCC Real URL�� ������ �� ���
#define COMMON_ERR_NOTSENDGET			(COMMON_ERR_BASE + 0x4F)		// GET Method�� �������� ����� �ǹ��� ��ȯ�ڵ�

#define COMMON_ERR_BADREQUEST			(HTTP_ERR_BASE	 + 0x400)		// �߸��� �䱸�Դϴ�.
#define COMMON_ERR_UNAUTHORIZED			(HTTP_ERR_BASE   + 0x401)		// �������� �ʾҽ��ϴ�.
#define COMMON_ERR_FORBIDDEN			(HTTP_ERR_BASE   + 0x403)		// �����Ǿ����ϴ�.
#define COMMON_ERR_NOTFOUND				(HTTP_ERR_BASE	 + 0x404)		// ����ڰ� ���� ���� �ʽ��ϴ�.
#define COMMON_ERR_NOTALLOWED			(HTTP_ERR_BASE   + 0x405)		// Method�� ����� �� �����ϴ�.
#define COMMON_ERR_NOTACCEPT			(HTTP_ERR_BASE   + 0x406)		// ������ �� �����ϴ�.
#define COMMON_ERR_NEEDPROXYAUTH		(HTTP_ERR_BASE   + 0x407)		// Proxy ������ �ʿ��մϴ�.
#define COMMON_ERR_HTTPTIMEOUT			(HTTP_ERR_BASE   + 0x408)		// TimeOut.
#define COMMON_ERR_CONFLICT				(HTTP_ERR_BASE   + 0x409)		// �浹�� �߻��Ͽ����ϴ�.
#define COMMON_ERR_GONE					(HTTP_ERR_BASE   + 0x410)		// ���빰�� ��������ϴ�.
#define COMMON_ERR_NEEDLENGTH			(HTTP_ERR_BASE   + 0x411)		// ���̰� �ʿ��մϴ�.
#define COMMON_ERR_PRECONDITION			(HTTP_ERR_BASE   + 0x412)		// ���� ������ ���� ���� ���߽��ϴ�.
#define COMMON_ERR_ENTITYBIG			(HTTP_ERR_BASE   + 0x413)		// Request Entity�� �ʹ� Ů�ϴ�.
#define COMMON_ERR_URLLONG				(HTTP_ERR_BASE   + 0x414)		// Request-URI�� �ʹ���ϴ�.
#define COMMON_ERR_MEDIATYPE			(HTTP_ERR_BASE   + 0x415)		// �������� �ʴ� Media Type�Դϴ�.
#define COMMON_ERR_BADRESPONSE			(HTTP_ERR_BASE	 + 0x415)		// �߸��� �����Դϴ�.
#define COMMON_ERR_INTERNALSVR          (HTTP_ERR_BASE   + 0x500)		// Internal Server Error

#define COMMON_ERR_HTTP_REQUEST_400     (HTTP_ERR_BASE	 + 0x400)		// This value is only HTTP Request Error Range
#define	COMMON_ERR_HTTP_REQUEST_499     (HTTP_ERR_BASE	 + 0x499)		// This value is only HTTP Request Error Range

//NAS Control
#define COMMON_ERR_NAS_PERFORMANCE		COMMON_ERR_BASE + 0x50			// Performance Query ����
#define COMMON_ERR_NAS_ALIVE			COMMON_ERR_BASE + 0x51			// Alive Check ����
#define COMMON_ERR_NAS_DISCONNECT		COMMON_ERR_BASE + 0x52			// NAS Drive Disconnect ����
#define COMMON_ERR_NAS_CONNECT			COMMON_ERR_BASE + 0x53			// NAS Drive Connect ����

// DLL linking
#define COMMON_ERR_DLLOPEN				COMMON_ERR_BASE + 0x60			// open dll dynamically ����

#endif	// _MEDIAERROR_H_

