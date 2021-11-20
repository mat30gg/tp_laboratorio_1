#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
		returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* returnAux;
	Node* aux;
	int x;
	returnAux = NULL;
	if(this != NULL)
	{
		if(nodeIndex < this->size && nodeIndex > -1)
		{
			aux = this->pFirstNode;
			for(x=0;x<nodeIndex;x++)
			{
				aux = aux->pNextNode;
			}
			returnAux = aux;
		}
	}
    return returnAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* newN;
	Node* aux;
	Node* siguiente;
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
		len = ll_len(this);
		if(nodeIndex > -1 && nodeIndex < len+1)
		{
			newN = (Node*) malloc(sizeof(Node));
			returnAux = 0;
			newN->pElement = pElement;
			if(nodeIndex == 0)
			{
				aux = this->pFirstNode;
				this->pFirstNode = newN;
				newN->pNextNode = aux;
			}
			else
			{
				aux = getNode(this, nodeIndex-1);
				siguiente = aux->pNextNode;
				aux->pNextNode = newN;
				newN->pNextNode = siguiente;
			}
		}
		this->size += 1;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int nodeIndex;
    if(this != NULL)
    {
		nodeIndex = ll_len(this);
		if(addNode(this, nodeIndex, pElement) == 0)
		{
			returnAux = 0;
		}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len;
    Node* nodeAux;
    if(this != NULL)
    {
    	nodeAux = (Node*) malloc(sizeof(Node));
    	len = ll_len(this);
    	if(index > -1 && index < len)
    	{
    		nodeAux = getNode(this, index);
    		returnAux = nodeAux->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* aux;
    if(this != NULL)
    {
    	len = ll_len(this);
    	if(index > -1 && index < len)
    	{
    		aux = getNode(this, index);
			if(aux != NULL)
			{
				returnAux = 0;
				aux->pElement = pElement;
			}
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* aux;
    Node* anterior;
    if(this != NULL)
    {
    	len = ll_len(this);
    	if(index > -1 && index < len)
    	{
    		returnAux = 0;
    		if(index == 0)
    		{
    			aux = this->pFirstNode;
    			this->pFirstNode = aux->pNextNode;
    		}
    		else
    		{
				anterior = getNode(this, index-1);
				aux = anterior->pNextNode;
				anterior->pNextNode = aux->pNextNode;
    		}
    		free(aux->pElement);
    		free(aux);
    		this->size -= 1;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int x;
    if(this != NULL)
    {
    	returnAux = 0;
    	len = ll_len(this);
    	for(x=0;x!=len;x++)
    	{
    		ll_remove(this, 0);
    	}
    	this->size = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;
    	ll_clear(this);
		free(this);
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int x;
    Node* aux;
    if(this != NULL)
    {
    	len = ll_len(this);
    	for(x=0;x<len;x++)
    	{
    		aux = getNode(this, x);
    		if(aux->pElement == pElement)
    		{
    			returnAux = x;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
		returnAux = 1;
    	if(ll_len(this) != 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
    	if(index > -1 && index < len+1)
    	{
    		returnAux = 0;
    		addNode(this, index, pElement);
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux;
    if(this != NULL)
    {
		returnAux = ll_get(this, index);
    	if(returnAux != NULL)
    	{
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    Node* aux;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	len = ll_len(this2);
    	for(int x=0;x<len;x++)
    	{
    		aux = getNode(this2, x);
    		if(ll_contains(this, aux->pElement) == 0)
    		{
    			returnAux = 0;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;
    Node* clon;
    int len;
    int x;
    if(this != NULL)
    {
    	len = ll_len(this);
		if(from > -1 && from < len+1)
		{
			if(to > from && to < len+1)
			{
				subList = ll_newLinkedList();
				for(x=from;x<to;x++)
				{
					clon = getNode(this, x);
					ll_add(subList, clon->pElement);
				}
			}
		}
    }
    return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneList = NULL;
    int len;
    if(this != NULL)
    {
    	len = ll_len(this);
    	cloneList = ll_subList(this, 0, len);
    }
    return cloneList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
	Node* xNode;
	Node* yNode;
	void* aux;
	int x;
	int y;
	int len;
	int res;
	if(this != NULL && *pFunc != NULL && (order == 0 || order == 1))
	{
		len =  ll_len(this);
		returnAux = 0;
		x = 0;
		do
		{
			xNode = getNode(this, x);
			y = x+1;
			while(y < len)
			{
				yNode = getNode(this, y);
				res = pFunc(xNode->pElement, yNode->pElement);
				if(res != 0)
				{
					if(res < 0 && order == 0)
					{
						aux = yNode->pElement;
						yNode->pElement = xNode->pElement;
						xNode->pElement = aux;
					}
					else
					{
						if(res > 0 && order == 1)
						{
							aux = xNode->pElement;
							xNode->pElement = yNode->pElement;
							yNode->pElement = aux;
						}
					}
				}
				y++;
			}

			x++;
		}
		while(x < len-1);
	}
	return returnAux;

}
