#include "stm32f10x.h"                  // Device header
#include "string.h"

uint16_t data[8];
uint16_t num=0,x,y;
uint8_t i=0;

int main(void){


	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	
	GPIOC->CRH |= (1<<20);
	GPIOC->CRH |= (1<<21);
	GPIOC->CRH &=~ (1<<22);
	GPIOC->CRH &=~ (1<<23);
	
	GPIOA->CRH |= (1<<4);
	GPIOA->CRH |= (1<<5);
	GPIOA->CRH &=~ (1<<6);
	GPIOA->CRH |= (1<<7);
	
	USART1->BRR = 0x1D4C;
	
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_UE;
	
	while(1){
	
		
	if(USART1->SR & USART_SR_RXNE){
	
		data[i]=USART1->DR;
		
		if(data[i]!='\n'){
		if(data[i] !='X' && data[i] !='Y'){
			num = (data[i] - '0') + (num * 10);
		}
		i++;
		if(data[0]=='X'){
		x=num;
		}
		if(data[0]=='Y'){
		y=num;
		}

	}
		if(data[i]=='\n'){
		num=0;
		i=0;
		}

	}
	

}
}