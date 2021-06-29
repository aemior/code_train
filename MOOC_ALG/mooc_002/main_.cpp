//BL2814 拨钟问题  by Guo Wei
#include <iostream>
#include <bitset>
#include <algorithm>
#include <functional>
#include <cstring>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
    Timer() : m_begin(high_resolution_clock::now()) {}
    void reset() { m_begin = high_resolution_clock::now(); }
    //默认输出毫秒
    int64_t elapsed() const
    {
        return duration_cast<chrono::milliseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //微秒
    int64_t elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_begin).count();
    } 
    //纳秒
    int64_t elapsed_nano() const
    {
        return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //秒
    int64_t elapsed_seconds() const
    {
        return duration_cast<chrono::seconds>(high_resolution_clock::now() - m_begin).count();
    }
    //分
    int64_t elapsed_minutes() const
    {
        return duration_cast<chrono::minutes>(high_resolution_clock::now() - m_begin).count();
    }
    //时
    int64_t elapsed_hours() const
    {
        return duration_cast<chrono::hours>(high_resolution_clock::now() - m_begin).count();
    }
private:
    time_point<high_resolution_clock> m_begin;
};

int oriClocks[9];
int clocks[9];
const char * moves[9] = { "ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI" };
int moveTimes[9] = {0};
int result[9];
int minTimes = 1 << 30;
int enmCNT = 0;
void Enum(int n) 
{
	if( n >= 9 ) {
    ++enmCNT;
		memcpy(clocks,oriClocks,sizeof(clocks));
		int totalTimes = 0;
		for( int i = 0;i < 9 ; ++ i ) { //依次进行9种移动
			if( moveTimes[i] ) { 
				for( int k = 0; moves[i][k]; ++k) {
					clocks[moves[i][k]-'A'] = (clocks[moves[i][k]-'A'] + moveTimes[i]) % 4;
					totalTimes += moveTimes[i];
				}
			}
		}
		int i;
		for( i = 0;i < 9; ++i )
			if( clocks[i])
				break;
		if( i == 9) {
			if( minTimes > totalTimes) {
				minTimes = totalTimes;
				memcpy(result,moveTimes,sizeof(result)); 
			} 
		}
		return ;
	}
	for( int i = 0;i < 4; ++ i ) {
		moveTimes[n] = i;
		Enum(n+1);
	}
	return ;
} 
int main()
{
	freopen("test.txt", "r", stdin);
  Timer t1;
	for( int i = 0;i < 9 ; ++i )
		cin >> oriClocks[i];
	Enum(0);
  cout << "elpased ms:" << t1.elapsed() << endl;
	for( int i = 0; i < 9; ++i )
		for( int k = 0; k < result[i] ; ++ k ) 
			cout << i+1 << " ";
  cout << enmCNT << endl;
	return 0;
}
