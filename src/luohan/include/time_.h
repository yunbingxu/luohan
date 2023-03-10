#ifndef USER_TIME_H
#define USER_TIME_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>


#ifdef __cplusplus
extern "C" {
#endif

#define TIME_STR_LEN        19 /* "YYYY-MM-DD HH:MM:SS" ?????????? */
#define IS_LEAP_YEAR(year)  ((year % 4 == 0 && year % 100) || year % 400 == 0)


#ifdef _WIN32
#    define LOCAL_TIME(pSec, pTm) localtime_s(pTm, pSec)
#else
#    define LOCAL_TIME(pSec, pTm) localtime_r(pSec, pTm)
#endif

typedef struct Timer_t Timer;

extern const uint8_t g_monthTab[];

extern time_t    timestr2second_(const char* str);
extern int       second2timestr_(char* timeStr, time_t sec);
extern struct tm second2tmStruct_(time_t sec);
extern int       getWeekDay_(int year, int month, int day);
extern int       checkTime_(struct tm* pdate);
extern int       delayMs_(int ms);
extern uint64_t  timeMs_(void);
extern uint64_t  cpuMs_(void);

/* ??ʱ?? */
extern int    timerRunning_(void);
extern bool   pastSecond_(void);
extern bool   pastMinute_(void);
extern bool   pastHour_(void);
extern bool   pastDay_(void);
extern bool   pastWeek_(void);
extern bool   pastMonth_(void);
extern bool   pastYear_(void);
extern Timer* timerInit_(const char* szStartTime, uint32_t intervalMs);
extern bool   timerRing_(Timer* timer);
extern int    timerDestroy_(Timer* timer);


#ifdef __cplusplus
}
#endif

#endif /* USR_TIME_H */