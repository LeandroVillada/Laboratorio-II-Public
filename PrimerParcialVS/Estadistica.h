#pragma once
class Estadistica
{
private:
	int _anio;
	float _recaudacion;

public:
	Estadistica();
	int getAnio();
	void setAnio(int anio);
	float getRecaudacion();
	void setRecaudacion(float recaudacion);
};
