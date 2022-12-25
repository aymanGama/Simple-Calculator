/*
 * utiles.h
 *
 * Created: 12/22/2022 6:19:21 PM
 *  Author: DR-Mosaad
 */ 


#ifndef UTILES_H_
#define UTILES_H_
void  Bin_Set(uint8_t  base , uint8_t  bit);
void	 Bin_Rest (uint8_t  base , uint8_t  bit);
void	 toggle_bit (uint8_t  reg , uint8_t  bit);
void Pin_Direction(uint8_t  base , uint8_t  bin , uint8_t  state ) ; //base is register bin
void Port_Direction(uint8_t  base  , uint8_t  state ) ; //base is register bin
uint8_t  Port_Read(uint8_t  base);

uint8_t  Port_Write(uint8_t  base , uint8_t  value);
uint8_t  Bin_Read(uint8_t  base , uint8_t   bin);
uint8_t  Bin_Write(uint8_t  base , uint8_t  bin, uint8_t  value);



#endif /* UTILES_H_ */