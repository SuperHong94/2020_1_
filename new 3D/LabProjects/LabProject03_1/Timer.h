#pragma once
//-----------------------------------------------------------------------------
// File: CGameTimer.h
//-----------------------------------------------------------------------------



//8주차 수정후
const ULONG MAX_SAMPLE_COUNT = 50;
class CGameTimer
{
public:
	CGameTimer();
	virtual ~CGameTimer();
	//타이머의 시간을 갱신한다. 
	void Tick(float fLockFPS = 0.0f);
	//프레임 레이트를 문자열로 반환한다. 
	unsigned long GetFrameRate(LPTSTR lpszString = NULL, int nCharacters = 0);

	//현재 프레임의 경과 시간을 반환한다.
	float GetTimeElapsed();
private:
	bool m_bHardwareHasPerformanceCounter;
	float m_fTimeScale;
	float m_fTimeElapsed;
	__int64 m_nCurrentTime;
	__int64 m_nLastTime;
	__int64 m_nPerformanceFrequency;
	float m_fFrameTime[MAX_SAMPLE_COUNT];
	ULONG m_nSampleCount;
	unsigned long m_nCurrentFrameRate;
	unsigned long m_nFramesPerSecond;
	float m_fFPSTimeElapsed;
};
