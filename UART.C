int main(void)
{
  char c;
  //Enable the UART module
  SYSCTL->RCGCUART |= (1<<0);
  //Enable the clock
  SYSCTL->RCGCPIO |= (1<<0);
  //
  GPIOA0->AFSEL = (1<<1) || (1<<0);
  
  GPIOA0->PCTDDDDDDD|| (1<<0);
 
}
