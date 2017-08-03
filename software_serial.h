// Expressed as 4-cycle delays (must never be 0!)
uint16_t _rx_delay_centering;
uint16_t _rx_delay_intrabit;
uint16_t _rx_delay_stopbit;
uint16_t _tx_delay;

void begin(long speed){
	_rx_delay_centering = _rx_delay_intrabit = _rx_delay_stopbit = _tx_delay = 0;

	uint16_t bit_delay = (F_CPU / speed) / 4;
}