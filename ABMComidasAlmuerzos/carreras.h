#ifndef CARRERAS_H_INCLUDED
#define CARRERAS_H_INCLUDED

typedef struct
{

    int id;
    char descripcion[20];

} eCarrera;


#endif // CARRERAS_H_INCLUDED

/** \brief
 *
 * \param carreras[] eCarrera
 * \param tam int
 * \return void
 *
 */
void mostrarCarreras(eCarrera carreras[], int tam);

/** \brief
 *
 * \param carrera eCarrera
 * \return void
 *
 */
void mostrarCarrera(eCarrera carrera);

/** \brief
 *
 * \param id int
 * \param carreras[] eCarrera
 * \param tam int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[]);
