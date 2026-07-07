/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  */
/* USER CODE END Header */
#include "main.h"
#include <stdint.h>

void SystemClock_Config(void);

/* USER CODE BEGIN 0 */
const uint8_t OLED_FontTable[][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00}, // ' ' (32)
    {0x00, 0x00, 0x5F, 0x00, 0x00}, // '!' (33)
    {0x00, 0x07, 0x00, 0x07, 0x00}, // '"' (34)
    {0x14, 0x7F, 0x14, 0x7F, 0x14}, // '#' (35)
    {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // '$' (36)
    {0x23, 0x13, 0x08, 0x64, 0x62}, // '%' (37)
    {0x36, 0x49, 0x55, 0x22, 0x50}, // '&' (38)
    {0x00, 0x05, 0x03, 0x00, 0x00}, // ''' (39)
    {0x00, 0x1C, 0x22, 0x41, 0x00}, // '(' (40)
    {0x00, 0x41, 0x22, 0x1C, 0x00}, // ')' (41)
    {0x08, 0x2A, 0x1C, 0x2A, 0x08}, // '*' (42)
    {0x08, 0x08, 0x3E, 0x08, 0x08}, // '+' (43)
    {0x00, 0x50, 0x30, 0x00, 0x00}, // ',' (44)
    {0x08, 0x08, 0x08, 0x08, 0x08}, // '-' (45)
    {0x00, 0x60, 0x60, 0x00, 0x00}, // '.' (46)
    {0x20, 0x10, 0x08, 0x04, 0x02}, // '/' (47)
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, // '0' (48)
    {0x00, 0x42, 0x7F, 0x40, 0x00}, // '1' (49)
    {0x42, 0x61, 0x51, 0x49, 0x46}, // '2' (50)
    {0x21, 0x41, 0x45, 0x4B, 0x31}, // '3' (51)
    {0x18, 0x14, 0x12, 0x7F, 0x10}, // '4' (52)
    {0x27, 0x45, 0x45, 0x45, 0x39}, // '5' (53)
    {0x3C, 0x4A, 0x49, 0x49, 0x30}, // '6' (54)
    {0x01, 0x71, 0x09, 0x05, 0x03}, // '7' (55)
    {0x36, 0x49, 0x49, 0x49, 0x36}, // '8' (56)
    {0x06, 0x49, 0x49, 0x52, 0x3C}, // '9' (57)
    {0x00, 0x36, 0x36, 0x00, 0x00}, // ':' (58)
    {0x00, 0x56, 0x36, 0x00, 0x00}, // ';' (59)
    {0x00, 0x08, 0x14, 0x22, 0x41}, // '<' (60)
    {0x14, 0x14, 0x14, 0x14, 0x14}, // '=' (61)
    {0x41, 0x22, 0x14, 0x08, 0x00}, // '>' (62)
    {0x02, 0x01, 0x51, 0x09, 0x06}, // '?' (63)
    {0x32, 0x49, 0x79, 0x41, 0x3E}, // '@' (64)
    {0x7E, 0x11, 0x11, 0x11, 0x7E}, // 'A' (65)
    {0x7F, 0x49, 0x49, 0x49, 0x36}, // 'B' (66)
    {0x3E, 0x41, 0x41, 0x41, 0x22}, // 'C' (67)
    {0x7F, 0x41, 0x41, 0x22, 0x1C}, // 'D' (68)
    {0x7F, 0x49, 0x49, 0x49, 0x41}, // 'E' (69)
    {0x7F, 0x09, 0x09, 0x01, 0x01}, // 'F' (70)
    {0x3E, 0x41, 0x41, 0x51, 0x32}, // 'G' (71)
    {0x7F, 0x08, 0x08, 0x08, 0x7F}, // 'H' (72)
    {0x00, 0x41, 0x7F, 0x41, 0x00}, // 'I' (73)
    {0x20, 0x40, 0x41, 0x3F, 0x01}, // 'J' (74)
    {0x7F, 0x08, 0x14, 0x22, 0x41}, // 'K' (75)
    {0x7F, 0x40, 0x40, 0x40, 0x40}, // 'L' (76)
    {0x7F, 0x02, 0x04, 0x02, 0x7F}, // 'M' (77)
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, // 'N' (78)
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, // 'O' (79)
    {0x7F, 0x09, 0x09, 0x09, 0x06}, // 'P' (80)
    {0x3E, 0x41, 0x51, 0x21, 0x5E}, // 'Q' (81)
    {0x7F, 0x09, 0x19, 0x29, 0x46}, // 'R' (82)
    {0x46, 0x49, 0x49, 0x49, 0x31}, // 'S' (83)
    {0x01, 0x01, 0x7F, 0x01, 0x01}, // 'T' (84)
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // 'U' (85)
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // 'V' (86)
    {0x7F, 0x20, 0x18, 0x20, 0x7F}, // 'W' (87)
    {0x63, 0x14, 0x08, 0x14, 0x63}, // 'X' (88)
    {0x03, 0x04, 0x78, 0x04, 0x03}, // 'Y' (89)
    {0x61, 0x51, 0x49, 0x45, 0x43}, // 'Z' (90)
    {0x00, 0x7F, 0x41, 0x41, 0x00}, // '[' (91)
    {0x02, 0x04, 0x08, 0x10, 0x20}, // '\' (92)
    {0x00, 0x41, 0x41, 0x7F, 0x00}, // ']' (93)
    {0x04, 0x02, 0x01, 0x02, 0x04}, // '^' (94)
    {0x40, 0x40, 0x40, 0x40, 0x40}, // '_' (95)
    {0x00, 0x01, 0x02, 0x04, 0x00}, // '`' (96)
    {0x20, 0x54, 0x54, 0x54, 0x78}, // 'a' (97)
    {0x7F, 0x48, 0x44, 0x44, 0x38}, // 'b' (98)
    {0x38, 0x44, 0x44, 0x44, 0x20}, // 'c' (99)
    {0x38, 0x44, 0x44, 0x48, 0x7F}, // 'd' (100)
    {0x38, 0x54, 0x54, 0x54, 0x18}, // 'e' (101)
    {0x08, 0x7E, 0x09, 0x01, 0x02}, // 'f' (102)
    {0x08, 0x54, 0x54, 0x54, 0x3C}, // 'g' (103)
    {0x7F, 0x08, 0x04, 0x04, 0x78}, // 'h' (104)
    {0x00, 0x44, 0x7D, 0x40, 0x00}, // 'i' (105)
    {0x20, 0x40, 0x44, 0x3D, 0x00}, // 'j' (106)
    {0x7F, 0x10, 0x28, 0x44, 0x00}, // 'k' (107)
    {0x00, 0x41, 0x7F, 0x40, 0x00}, // 'l' (108)
    {0x7C, 0x04, 0x18, 0x04, 0x78}, // 'm' (109)
    {0x7C, 0x08, 0x04, 0x04, 0x78}, // 'n' (110)
    {0x38, 0x44, 0x44, 0x44, 0x38}, // 'o' (111)
    {0x7C, 0x14, 0x14, 0x14, 0x08}, // 'p' (112)
    {0x08, 0x14, 0x14, 0x18, 0x7C}, // 'q' (113)
    {0x7C, 0x08, 0x04, 0x04, 0x08}, // 'r' (114)
    {0x48, 0x54, 0x54, 0x54, 0x20}, // 's' (115)
    {0x04, 0x3F, 0x44, 0x40, 0x20}, // 't' (116)
    {0x3C, 0x40, 0x40, 0x20, 0x7C}, // 'u' (117)
    {0x1C, 0x20, 0x40, 0x20, 0x1C}, // 'v' (118)
    {0x3C, 0x40, 0x30, 0x40, 0x3C}, // 'w' (119)
    {0x44, 0x28, 0x10, 0x28, 0x44}, // 'x' (120)
    {0x0C, 0x50, 0x50, 0x50, 0x3C}, // 'y' (121)
    {0x44, 0x64, 0x54, 0x4C, 0x44}, // 'z' (122)
    {0x00, 0x08, 0x36, 0x41, 0x00}, // '{' (123)
    {0x00, 0x00, 0x7F, 0x00, 0x00}, // '|' (124)
    {0x00, 0x41, 0x36, 0x08, 0x00}, // '}' (125)
    {0x08, 0x08, 0x2A, 0x1C, 0x08}, // '~' (126)
};

//===== GPIOB =====
volatile uint32_t* RCC_AHB1ENR  = (volatile uint32_t*)0x40023830;
volatile uint32_t* GPIOB_MODER  = (volatile uint32_t*)0x40020400;
volatile uint32_t* GPIOB_OTYPER = (volatile uint32_t*)0x40020404;
volatile uint32_t* GPIOB_ODR    = (volatile uint32_t*)0x40020414;
volatile uint32_t* GPIOB_IDR    = (volatile uint32_t*)0x40020410;
volatile uint32_t* GPIOB_AFRL   = (volatile uint32_t*)0x40020420;
volatile uint32_t* GPIOB_PUPDR = (volatile uint32_t*)0x4002040C;

//===== GPIOA =====
volatile uint32_t* GPIOA_MODER  = (volatile uint32_t*)0x40020000;
volatile uint32_t* GPIOA_AFRL   = (volatile uint32_t*)0x40020020;

//===== GPIOC =====
volatile uint32_t* GPIOC_MODER  = (volatile uint32_t*)0x40020800;
volatile uint32_t* GPIOC_IDR    = (volatile uint32_t*)0x40020810;

//===== I2C1 =====
volatile uint32_t* RCC_APB1ENR  = (volatile uint32_t*)0x40023840;
volatile uint32_t* I2C1_CR1     = (volatile uint32_t*)0x40005400;
volatile uint32_t* I2C1_CR2     = (volatile uint32_t*)0x40005404;
volatile uint32_t* I2C1_DR      = (volatile uint32_t*)0x40005410;
volatile uint32_t* I2C1_SR1     = (volatile uint32_t*)0x40005414;
volatile uint32_t* I2C1_SR2     = (volatile uint32_t*)0x40005418;
volatile uint32_t* I2C1_CCR     = (volatile uint32_t*)0x4000541C;
volatile uint32_t* I2C1_TRISE   = (volatile uint32_t*)0x40005420;

//===== USART2 =====
volatile uint32_t* USART2_SR    = (volatile uint32_t*)0x40004400;
volatile uint32_t* USART2_DR    = (volatile uint32_t*)0x40004404;
volatile uint32_t* USART2_BRR   = (volatile uint32_t*)0x40004408;
volatile uint32_t* USART2_CR1   = (volatile uint32_t*)0x4000440C;

//===== TIM2 =====
volatile uint32_t* TIM2_CR1     = (volatile uint32_t*)0x40000000;
volatile uint32_t* TIM2_PSC     = (volatile uint32_t*)0x40000028;
volatile uint32_t* TIM2_ARR     = (volatile uint32_t*)0x4000002C;
volatile uint32_t* TIM2_CNT     = (volatile uint32_t*)0x40000024;
volatile uint32_t* TIM2_EGR     = (volatile uint32_t*)0x40000014;

//===== PROTOTYPES =====
void I2C_Start(void);
void I2C_Address(uint8_t addr);
void I2C_Write(uint8_t data);
void I2C_Stop(void);
void OLED_SendCommand(uint8_t cmd);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_SetCursor(uint8_t page, uint8_t col);
void OLED_WriteChar(char c);
void OLED_WriteString(char *str);
void delay_us(uint32_t us);
void DHT11_SetOutput(void);
void DHT11_SetInput(void);
uint8_t DHT11_Read(uint8_t *temp, uint8_t *hum);
void send_char(char ch);
void send_string(char *str);

/* USER CODE END 0 */

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    /* USER CODE BEGIN 2 */

    // GPIOA clock (for USART2)
    *RCC_AHB1ENR |= (1U << 0);

    // GPIOB clock + PB2 input (DHT11) + clear PB6/PB7 bits
    *RCC_AHB1ENR |= (1U << 1);
    *GPIOB_MODER &= ~(3U << 4);   // PB2 = input
    *GPIOB_PUPDR &= ~(3U<<4);  // clear
    *GPIOB_PUPDR |=  (1U<<4);  // PB2 pull-up enabled
    *GPIOB_MODER &= ~(15U << 12); // clear PB6, PB7

    // GPIOC clock + PC13 input (user button)
    *RCC_AHB1ENR |= (1U << 2);
    *GPIOC_MODER &= ~(3U << 26);  // PC13 = input

    // PB6/PB7 open drain AF4 for I2C1
    *GPIOB_OTYPER |= (1U << 6);
    *GPIOB_OTYPER |= (1U << 7);
    *GPIOB_MODER  |= (10U << 12);
    *GPIOB_AFRL   &= ~(15U << 24);
    *GPIOB_AFRL   |=  (4U << 24);
    *GPIOB_AFRL   &= ~(15U << 28);
    *GPIOB_AFRL   |=  (4U << 28);

    // PA2/PA3 AF7 for USART2
    *GPIOA_MODER &= ~(15U << 4);
    *GPIOA_MODER |=  (10U << 4);
    *GPIOA_AFRL  &= ~(15U << 8);
    *GPIOA_AFRL  |=  (7U << 8);
    *GPIOA_AFRL  &= ~(15U << 12);
    *GPIOA_AFRL  |=  (7U << 12);

    // TIM2 — 1us tick
    *RCC_APB1ENR |= (1U << 0);
    *TIM2_PSC     = 15;
    *TIM2_ARR     = 0xFFFFFFFF;
    *TIM2_EGR    |= (1U << 0);
    *TIM2_CR1    |= (1U << 0);

    // USART2 — 9600 baud
    *RCC_APB1ENR |= (1U << 17);
    *USART2_BRR   = 0x683;
    *USART2_CR1  |= (1U << 2);
    *USART2_CR1  |= (1U << 3);
    *USART2_CR1  |= (1U << 13);

    // I2C1
    *RCC_APB1ENR |= (1U << 21);
    *I2C1_CR2    |= 16U;
    *I2C1_CCR     = 80;
    *I2C1_TRISE   = 17;
    *I2C1_CR1    |= (1U << 0);

    // OLED startup
    OLED_Init();
    OLED_Clear();
    OLED_SetCursor(0, 0);
    OLED_WriteString("Press button");

    /* USER CODE END 2 */

    uint8_t temp = 0, hum = 0, ok = 0;
    char dbuf[20];
    delay_us(2000000);  // 2 second startup delay for DHT11

    while (1)
    {
    	if (!((*GPIOC_IDR >> 13) & 0x01))
    	{
    	    while (!((*GPIOC_IDR >> 13) & 0x01));

    	    ok = DHT11_Read(&temp, &hum);

    	    OLED_Init();
    	    OLED_Clear();

    	    OLED_SetCursor(0, 0);
    	    dbuf[0]='o'; dbuf[1]='k'; dbuf[2]='='; dbuf[3]='0'+ok; dbuf[4]='\0';
    	    OLED_WriteString(dbuf);

    	    OLED_SetCursor(1, 0);
    	    dbuf[0]='t'; dbuf[1]='=';
    	    dbuf[2]='0'+(temp/10); dbuf[3]='0'+(temp%10);
    	    dbuf[4]='\0';
    	    OLED_WriteString(dbuf);

    	    OLED_SetCursor(2, 0);
    	    dbuf[0]='h'; dbuf[1]='=';
    	    dbuf[2]='0'+(hum/10); dbuf[3]='0'+(hum%10);
    	    dbuf[4]='\0';
    	    OLED_WriteString(dbuf);

    	    send_string("ok=");
    	    send_char('0'+ok);
    	    send_string(" t=");
    	    send_char('0'+(temp/10));
    	    send_char('0'+(temp%10));
    	    send_string(" h=");
    	    send_char('0'+(hum/10));
    	    send_char('0'+(hum%10));
    	    send_string("\r\n");
    	}
    }
}

//===================== DELAY =====================
void delay_us(uint32_t us){
    *TIM2_CNT = 0;
    while(*TIM2_CNT < us);
}

//===================== DHT11 =====================
void DHT11_SetOutput(void){
    *GPIOB_MODER &= ~(3U<<4);
    *GPIOB_MODER |=  (1U<<4);    // output mode
    *GPIOB_OTYPER &= ~(1U<<2);   // push-pull (not open-drain)
}

void DHT11_SetInput(void){
    *GPIOB_MODER &= ~(3U<<4);   // input mode
    *GPIOB_PUPDR &= ~(3U<<4);   // clear
    *GPIOB_PUPDR |=  (1U<<4);   // pull-up
}

uint8_t DHT11_Read(uint8_t *temp, uint8_t *hum){
    uint8_t data[5] = {0};
    uint32_t count;

    // Step 1: Start signal
    DHT11_SetOutput();
    *GPIOB_ODR &= ~(1U<<2);
    delay_us(18000);
    *GPIOB_ODR |=  (1U<<2);
    delay_us(30);
    DHT11_SetInput();

    // Step 2: Wait for response
    count = 0;
    while(!(*GPIOB_IDR & (1U<<2)) && count < 10000) count++;
    if(count >= 10000) return 0;

    count = 0;
    while((*GPIOB_IDR & (1U<<2)) && count < 10000) count++;
    if(count >= 10000) return 0;

    count = 0;
    while(!(*GPIOB_IDR & (1U<<2)) && count < 10000) count++;
    if(count >= 10000) return 0;

    // Step 3: Read 40 bits
    for(int byte = 0; byte < 5; byte++){
        for(int bit = 0; bit < 8; bit++){
            count = 0;
            while(!(*GPIOB_IDR & (1U<<2)) && count < 10000) count++;
            if(count >= 10000) return 0;

            count = 0;
            while((*GPIOB_IDR & (1U<<2)) && count < 10000){
                count++;
                delay_us(1);
            }
            data[byte] <<= 1;
            if(count > 14) data[byte] |= 1;  // lower threshold
        }
    }

    // Step 4: Checksum
    if((data[0]+data[1]+data[2]+data[3]) != data[4]) return 0;

    *hum  = data[0];
    *temp = data[2];
    return 1;
}

//===================== UART =====================
void send_char(char ch){
    while(!((*USART2_SR >> 7) & 0x01));
    *USART2_DR = ch;
}

void send_string(char *str){
    while(*str){ send_char(*str); str++; }
}

//===================== I2C =====================
void I2C_Start(void){
    *I2C1_CR1 |= (1U<<8);
    while(!((*I2C1_SR1>>0)&0x01));
}

void I2C_Address(uint8_t addr){
    *I2C1_DR = addr;
    while(!((*I2C1_SR1>>1)&0x01));
    uint32_t t1 = *I2C1_SR1;
    uint32_t t2 = *I2C1_SR2;
    (void)t1; (void)t2;
}

void I2C_Write(uint8_t data){
    while(!((*I2C1_SR1>>7)&0x01));
    *I2C1_DR = data;
    while(!((*I2C1_SR1>>2)&0x01));
}

void I2C_Stop(void){
    *I2C1_CR1 |= (1U<<9);
}

//===================== OLED =====================
void OLED_SendCommand(uint8_t cmd){
    I2C_Start();
    I2C_Address(0x3C<<1);
    I2C_Write(0x00);
    I2C_Write(cmd);
    I2C_Stop();
}

void OLED_Init(void){
    OLED_SendCommand(0x8D); OLED_SendCommand(0x14);
    OLED_SendCommand(0xAE);
    OLED_SendCommand(0x20); OLED_SendCommand(0x00);
    OLED_SendCommand(0xB0);
    OLED_SendCommand(0xC8);
    OLED_SendCommand(0x00);
    OLED_SendCommand(0x10);
    OLED_SendCommand(0x40);
    OLED_SendCommand(0x81); OLED_SendCommand(0xFF);
    OLED_SendCommand(0xA1);
    OLED_SendCommand(0xA6);
    OLED_SendCommand(0xA8); OLED_SendCommand(0x3F);
    OLED_SendCommand(0xA4);
    OLED_SendCommand(0xD3); OLED_SendCommand(0x00);
    OLED_SendCommand(0xD5); OLED_SendCommand(0x80);
    OLED_SendCommand(0xD9); OLED_SendCommand(0xF1);
    OLED_SendCommand(0xDA); OLED_SendCommand(0x12);
    OLED_SendCommand(0xDB); OLED_SendCommand(0x40);
    OLED_SendCommand(0xAF);
}

void OLED_Clear(void){
    OLED_SendCommand(0x21); OLED_SendCommand(0x00); OLED_SendCommand(0x7F);
    OLED_SendCommand(0x22); OLED_SendCommand(0x00); OLED_SendCommand(0x07);
    I2C_Start();
    I2C_Address(0x3C<<1);
    I2C_Write(0x40);
    for(int i = 0; i < 1024; i++) I2C_Write(0x00);
    I2C_Stop();
}

void OLED_SetCursor(uint8_t page, uint8_t col){
    OLED_SendCommand(0xB0 + page);
    OLED_SendCommand(0x00 + (col & 0x0F));
    OLED_SendCommand(0x10 + (col >> 4));
}

void OLED_WriteChar(char c){
    uint8_t idx = c - 32;
    I2C_Start();
    I2C_Address(0x3C<<1);
    I2C_Write(0x40);
    for(int i = 0; i < 5; i++) I2C_Write(OLED_FontTable[idx][i]);
    I2C_Write(0x00);
    I2C_Stop();
}

void OLED_WriteString(char *str){
    while(*str){ OLED_WriteChar(*str); str++; }
}

//===================== SYSTEM CLOCK =====================
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) Error_Handler();
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) Error_Handler();
}

void Error_Handler(void){
    __disable_irq();
    while(1){}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line){}
#endif
