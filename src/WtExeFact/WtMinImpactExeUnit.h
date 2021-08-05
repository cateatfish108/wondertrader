/*!
 * \file WtMinImpactExeUnit.h
 *
 * \author Wesley
 * \date 2020/03/30
 *
 * ��С���ִ�е�Ԫ
 */
#pragma once
#include "../Includes/ExecuteDefs.h"
#include "WtOrdMon.h"

USING_NS_OTP;

class WtMinImpactExeUnit : public ExecuteUnit
{
public:
	WtMinImpactExeUnit();
	virtual ~WtMinImpactExeUnit();

private:
	void	do_calc();

public:
	/*
	 *	����ִ������������
	 */
	virtual const char* getFactName() override;

	/*
	 *	ִ�е�Ԫ����
	 */
	virtual const char* getName() override;

	/*
	 *	��ʼ��ִ�е�Ԫ
	 *	ctx		ִ�е�Ԫ���л���
	 *	code	�����ĺ�Լ����
	 */
	virtual void init(ExecuteContext* ctx, const char* stdCode, WTSVariant* cfg) override;

	/*
	 *	�����ر�
	 *	localid	���ص���
	 *	code	��Լ����
	 *	isBuy	��or��
	 *	leftover	ʣ������
	 *	price	ί�м۸�
	 *	isCanceled	�Ƿ��ѳ���
	 */
	virtual void on_order(uint32_t localid, const char* stdCode, bool isBuy, double leftover, double price, bool isCanceled) override;

	/*
	 *	tick���ݻص�
	 *	newTick	���µ�tick����
	 */
	virtual void on_tick(WTSTickData* newTick) override;

	/*
	 *	�ɽ��ر�
	 *	code	��Լ����
	 *	isBuy	��or��
	 *	vol		�ɽ�����,����û������,ͨ��isBuyȷ�����뻹������
	 *	price	�ɽ��۸�
	 */
	virtual void on_trade(uint32_t localid, const char* stdCode, bool isBuy, double vol, double price) override;

	/*
	 *	�µ�����ر�
	 */
	virtual void on_entrust(uint32_t localid, const char* stdCode, bool bSuccess, const char* message) override;

	/*
	 *	�����µ�Ŀ���λ
	 *	code	��Լ����
	 *	newVol	�µ�Ŀ���λ
	 */
	virtual void set_position(const char* stdCode, double newVol) override;

	/*
	 *	����ͨ�������ص�
	 */
	virtual void on_channel_ready() override;

	/*
	 *	����ͨ����ʧ�ص�
	 */
	virtual void on_channel_lost() override;

private:
	WTSTickData* _last_tick;	//��һ������
	double		_target_pos;	//Ŀ���λ

	WTSCommodityInfo*	_comm_info;
	WTSSessionInfo*		_sess_info;

	//////////////////////////////////////////////////////////////////////////
	//ִ�в���
	int32_t		_price_offset;
	uint32_t	_expire_secs;
	int32_t		_price_mode;
	uint32_t	_entrust_span;
	bool		_by_rate;
	double		_order_lots;
	double		_qty_rate;

	WtOrdMon	_orders_mon;
	uint32_t	_cancel_cnt;
	uint32_t	_cancel_times;

	uint64_t	_last_place_time;
};
