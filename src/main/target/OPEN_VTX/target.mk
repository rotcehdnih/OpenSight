F405_TARGETS   += $(TARGET)
FEATURES       += VCP

TARGET_SRC = \
		   drivers/accgyro_spi_mpu9250.c \
            drivers/compass_hmc5883l.c \
            drivers/light_ws2811strip.c \
            drivers/light_ws2811strip_stm32f4xx.c\
            drivers/vtx_rtc6705.c \
            io/vtx.c

