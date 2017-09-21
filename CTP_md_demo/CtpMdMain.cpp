#include ".\ThostTraderApi\ThostFtdcMdApi.h"
#include "MdSpi.h"

CThostFtdcMdApi* pUserApi; // UserApi����

char FRONT_ADDR[] = "tcp://180.168.146.187:10011";		// ǰ�õ�ַ
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "059979";		// Ͷ���ߴ���
TThostFtdcPasswordType  PASSWORD = "Krazy49";			// �û�����
char *ppInstrumentID[] = {"cu1710", "cu1801"};			// ���鶩���б�
int iInstrumentID = 2;									// ���鶩������
int iRequestID = 0;                                     // ������

void main(void)
{
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// ����UserApi

	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	pUserApi->RegisterSpi(pUserSpi);						// ע���¼���
	pUserApi->RegisterFront(FRONT_ADDR);					// connect
	pUserApi->Init();
	pUserApi->Join();
    pUserApi->Release();
}
