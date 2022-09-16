#pragma once

class Venta
{
private:
	int _codigo;
	float _precio;
	int _cantidad;
	bool _estado;
public:
	// CONSTRUCTOR
	Venta();
	Venta(int codigo, float precio, int cantidad);
	// SETTERS
	void setCodigo(int);
	void setPrecio(float);
	void setCantidad(int);
	void setEstado(bool);

	void setVenta(Venta venta);

	// GETTERS
	int getCodigo();
	float getPrecio();
	int getCantidad();
	bool getEstado();

	float getTotal();
};

