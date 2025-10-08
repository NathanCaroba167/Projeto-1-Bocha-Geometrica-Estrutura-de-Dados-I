//
// Created by natha on 19/09/2025.
//

#ifndef TEXTO_H
#define TEXTO_H
/*
 Módulo encarregado de coordenar um texto com operações de criar, get, set, calcularArea, calcularExtremos e eliminar
*/

/*
 Ponteiro void Texto
 */
typedef void* Texto;

/// @brief Cria um texto com os atributos indicados
/// @param i Identificador unico que se refere ao texto
/// @param x Coordenada x do ponto âncora do texto
/// @param y Coordenada y do ponto âncora do texto
/// @param corB Cor de borda do texto
/// @param corP Cor de preenchimento do texto
/// @param a Ponto âncora do texto ('i' - Inìcio // 'm' - Meio // 'f' - Fim)
/// @param txt O conteúdo do texto (o texto em si)
/// @param fFamily Família da fonte do texto
/// @param fWeight Peso da fonte do texto
/// @param fSize Tamanho da fonte do texto
/// @return Ponteiro para o texto criado
/// @warning
Texto CriarTexto(int i, double x, double y, char* corB, char* corP, char a, char* txt, char* fFamily ,char* fWeight, char* fSize);

/// @brief Pega o ID do texto sem modifica-lo
/// @param t Ponteiro para o texto analisada
/// @return Um inteiro que representa o ID do texto
/// @warning
int getIdTexto(Texto t);

/// @brief Define o ID do texto
/// @param t Ponteiro para o texto onde o ID será definido
/// @param id ID que será definido
/// @warning
void setIdTexto(Texto t, int id);

/// @brief Pega a coordenada x do ponto âncora do texto sem modifica-la
/// @param t Ponteiro para o texto analisada
/// @return Um double que representa a coordenada x do ponto âncora do texto
/// @warning
double getXTexto(Texto t);

/// @brief Define a nova coordenada x do ponto âncora do texto
/// @param t Ponteiro para o texto onde a coordenada x do ponto âncora será definida
/// @param x1 Nova coordenada x do ponto âncora do texto que será definida
/// @warning
void setXTexto(Texto t, double x1);

/// @brief Pega a coordenada y do ponto âncora do texto sem modifica-la
/// @param t Ponteiro para o texto analisado
/// @return Um double que representa a coordenada y do ponto âncora do texto
/// @warning
double getYTexto(Texto t);

/// @brief Define a nova coordenada y do ponto âncora do texto
/// @param t Ponteiro para o texto onde a coordenada y do ponto âncora será definida
/// @param y1 Nova coordenada y do ponto âncora do texto que será definida
/// @warning
void setYTexto(Texto t, double y1);

/// @brief Pega a cor de borda do texto sem modifica-la
/// @param t Ponteiro para o texto analisado
/// @return Uma string com a cor de borda do texto
/// @warning
char* getCorBTexto(Texto t);

/// @brief Define a nova cor de borda do texto
/// @param t Ponteiro para o texto onde a cor de borda será definida
/// @param corB Nova cor de borda que será definida
/// @warning
void setCorBTexto(Texto t,char* corB);

/// @brief Pega a cor de preenchimento do texto sem modifica-la
/// @param t Ponteiro para o texto analisado
/// @return Uma string com a cor de preenchimento do texto
/// @warning
char* getCorPTexto(Texto t);

/// @brief Define a nova cor de preenchimento do texto
/// @param t Ponteiro para o texto onde a cor de preenchimento será definida
/// @param corP Nova cor de preenchimento que será definida
/// @warning
void setCorPTexto(Texto t,char* corP);

/// @brief Pega a âncora do texto sem modifica-la
/// @param t Ponteiro para o texto analisado
/// @return Um caractere que representa a âncora do texto
/// @warning
char getATexto(Texto t);

/// @brief Define a nova âncora do texto
/// @param t Ponteiro para o texto onde a âncora será definida
/// @param a Nova âncora que será definida
/// @warning
void setATexto(Texto t, char a);///

/// @brief Pega o conteúdo do texto sem modifica-lo
/// @param t Ponteiro para o texto analisado
/// @return Uma string que representa o conteúdo do texto
/// @warning
char* getTxtTexto(Texto t);

/// @brief Define o novo conteúdo do texto
/// @param t Ponteiro para o texto onde o conteúdo será definido
/// @param txt Novo conteúdo que será definido
/// @warning
void setTxtTexto(Texto t, char* txt);

/// @brief Pega a família da fonte do texto sem modifica-lo
/// @param t Ponteiro para o texto analisado
/// @return Uma string que representa a família da fonte do texto
/// @warning
char* getFontFamilyTexto(Texto t);///

/// @brief Define a nova família da fonte do texto
/// @param t Ponteiro para o texto onde a família da fonte será definida
/// @param family Nova família da fonte que será definida
/// @warning
void setFontFamilyTexto(Texto t, char* family);///

/// @brief Pega o peso da fonte do texto sem modifica-lo
/// @param t Ponteiro para o texto analisado
/// @return Uma string que representa o peso da fonte do texto
/// @warning
char* getFontWeightTexto(Texto t);///

/// @brief Define o novo peso da fonte do texto
/// @param t Ponteiro para o texto onde o peso da fonte será definido
/// @param weight Novo peso da fonte que será definido
/// @warning
void setFontWeightTexto(Texto t, char* weight);///

/// @brief Pega o tamanho da fonte do texto sem modifica-lo
/// @param t Ponteiro para o texto analisado
/// @return Uma string que representa o tamanho da fonte do texto
/// @warning
char* getFontSizeTexto(Texto t);///

/// @brief Define o novo tamanho da fonte do texto
/// @param t Ponteiro para o texto onde o tamanho da fonte será definido
/// @param size Novo tamanho da fonte que será definido
/// @warning
void setFontSizeTexto(Texto t, char* size);///

/// @brief Calcula os pontos extremos do texto(inicio e fim)
/// @param t Ponteiro para o texto analisado
/// @warning
void calcExtremosTexto(Texto t);////

/// @brief Calcula a área do texto
/// @param t Ponteiro para o texto analisado
/// @return Um double que representa a área do texto
/// @warning
/// @details 20 * número de caracteres
double calcAreaTexto(Texto t);

/// @brief Libera a memória alocada para o texto
/// @param t Ponteiro para o texto analisado
/// @warning
void eliminarTexto(Texto t);

#endif //TEXTO_H
