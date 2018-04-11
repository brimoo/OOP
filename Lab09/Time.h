#ifndef TIME_H
#define TIME_H
#include <cmath>

class Time
{

    float hours, minutes, seconds;

    public:

        Time(float h, float m, float s): hours(h), minutes(m), seconds(s){}

        float getHours(){return hours;}

        float getMinutes(){return minutes;}

        float getSeconds(){return seconds;}

        void add(const Time &t)
        {
            if(hours + t.hours > 24)
                hours = hours + t.hours - 24;
            else
                hours += t.hours;

            if(minutes + t.minutes >= 60){
                minutes = minutes + t.minutes - 60;
                hours ++;
            }else
                minutes += t.minutes;

            if(seconds + t.seconds >= 60){
                seconds = seconds + t.seconds - 60;
                minutes++;
            }else
                seconds += t.seconds;
        }

        void getAngles(float &h, float &m, float &s)
        { 
            if(minutes >= 45)
                m = (minutes - 15) * (M_PI / 30) * -1;
            else
                m = (15 - minutes) * (M_PI / 30);

            if(seconds >= 45)
                s = (seconds - 15) * (M_PI / 30) * -1;
            else
                s = (15 - seconds) * (M_PI / 30);

            if(hours >= 9 || hours < 3)
                h = ((hours - (minutes / 60)) - 3) * (M_PI / 6);
            else
                h = (3 - (hours + (minutes / 60))) * (M_PI / 6);
        }

        void getHourCoords(float &x, float &y)
        {
            float h, m, s;
            getAngles(h, m, s);

            x = cos(h);
            y = sin(h);
        }

        void getMinuteCoords(float &x, float &y)
        {
            float h, m, s;
            getAngles(h, m, s);

            x = cos(m);
            y = sin(m);
        }

        void getSecondsCoords(float &x, float &y)
        {
            float h, m, s;
            getAngles(h, m, s);

            x = cos(s);
            y = sin(s);
        }
};

#endif
