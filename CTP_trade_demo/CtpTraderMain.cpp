#include ".\ThostTraderApi\ThostFtdcTraderApi.h"
#include "TraderSpi.h"

CThostFtdcTraderApi* pUserApi;  // UserApi����

char  FRONT_ADDR[] = "tcp://180.168.146.187:10001";		// ǰ�õ�ַ
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "059979";		// Ͷ���ߴ���
TThostFtdcPasswordType  PASSWORD = "Krazy49";			// �û�����
TThostFtdcInstrumentIDType INSTRUMENT_ID = "CF801";	    // ��Լ����
//TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// ��������
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Buy;     // ping jin THOST_FTDC_OF_CloseToday  THOST_FTDC_OF_Close
TThostFtdcPriceType	LIMIT_PRICE = 15350;  // 38850;		 // �۸�
int iRequestID = 0;   // ������

void insertRequest()
{
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// ��ʼ������UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// ע���¼���
    pUserApi->SubscribePublicTopic(THOST_TERT_QUICK);				// ע�ṫ����
    pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// ע��˽����
    pUserApi->RegisterFront(FRONT_ADDR);							// connect
    pUserApi->Init();
    pUserApi->Join();
    pUserApi->Release();
}

int main(int argc, char* argv[])
{
     insertRequest();
     return 0;
}
