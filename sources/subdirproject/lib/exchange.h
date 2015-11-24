#ifndef EXCHANGE_H
#define EXCHANGE_H

#ifdef __cplusplus
extern "C" {
#endif

struct purse
{
     int ones;
     int twos;
     int fives;
};

struct purse change_by_coins(int amount);

#ifdef __cplusplus
}
#endif

#endif // EXCHANGE_H
