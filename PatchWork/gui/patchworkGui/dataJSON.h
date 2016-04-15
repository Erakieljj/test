#ifndef DATAJSON_H
#define DATAJSON_H

#include <QJsonObject>
#include <string>
#include "objectinterface.h"

static vector<ObjectInterface*> mShapes; //penser au clear et init
typedef struct  {
    QString nbColorAccepted;
    QString nbShapesRequired;
    QString sumAreaAccepted;
    float sumAreaShapeRequired;
}Annotations;
/**
 * @brief La classe DataJSON permet la gestion d'un document JSON dans les interactions client/serveur.
 * Cette classe fournit uniquement des méthodes statiques.
 */
class DataJSON
{
    private:
         /**
         * @brief readShapeJSON Lecture concernant les attributs associés à un objet.
         * @param json JSON à parser
         * @param obj Objet stockant les information du JSON.
         */
        static void readShapeJSON(const QJsonObject &json, ObjectInterface &obj);
    public:
        //DataJSON();
         /**
         * @brief getShapes Obtient la liste des figures géométriques.
         * @return Retourne un ensemble de figure géométrique.
         */
        static const vector<ObjectInterface*> &getShapes();
        /**
         * @brief setShapes Met à jour la listes des figures géométriques.
         * @param shapes Liste des figures géométriques.
         */
        static void setShapes(const vector<ObjectInterface*> &shapes);
        /**
         * @brief readDrawing Lecture d'un JSON pour parser le dessin d'un élève (coté serveur).
         * @param json JSON à lire et parser.
         */
        static vector<ObjectInterface*> readDrawing(const QJsonObject &json);
        /**
         * @brief writeDrawing Ecriture d'un JSON associé au format de dessin d'un élève(coté client).
         * @param json JSON à créer.
         */
        static void writeDrawing(QJsonObject &json);
        /**
         * @brief writeJsonAnnotation Ecriture d'un JSON avec les annotation de la maîtresse(coté serveur -> client).
         * @param json JSON à créer.
         */
        static void writeJsonAnnotation(QJsonObject &json);
        /**
         * @brief readJsonAnnotation Lecture d'un JSON contenant les annotations de la maîtresse (provenant du serveur).
         * @param json JSON à lire et parser.
         * @return Retourne les annotation de la maîtresse.
         */
        static Annotations readJsonAnnotation(QJsonObject &json);

};

#endif // DATAJSON_H
