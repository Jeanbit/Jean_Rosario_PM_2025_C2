#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILE_VEH "vehiculos.db.txt"
#define FILE_CFG "config.db.txt"

typedef struct {
    char placa[15];
    char marca[20];
    char modelo[20];
    char tipoCombustible[10]; // Gasolina o Gasoil
    float kmxGalonCarretera;
    float kmxGalonCiudad;
    float costoGomas;
    int   kmGomas;
    float costoSeguroAnual;
    float costoMantenimiento;
    int   kmMantenimiento;
    float costoVehiculo;
    int   vidaUtil;    // anios
    int   kmAnuales;   // promedio
} Vehiculo;

static Vehiculo vehiculos[MAX];
static int totalVehiculos = 0;

static float costoGasolina = 0.0f;
static float costoGasoil   = 0.0f;

// ---------- helpers de IO ----------
void pausar() {
    printf("\nPresione ENTER para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    getchar();
}

int leerLinea(char *buf, size_t n) {
    if (!fgets(buf, (int)n, stdin)) return 0;
    size_t len = strlen(buf);
    if (len && buf[len-1] == '\n') buf[len-1] = '\0';
    return 1;
}

// ---------- persistencia ----------
int guardarVehiculos() {
    FILE *f = fopen(FILE_VEH, "w");
    if (!f) return 0;
    // Formato separado por |
    for (int i = 0; i < totalVehiculos; i++) {
        Vehiculo *v = &vehiculos[i];
        fprintf(f, "%s|%s|%s|%s|%.6f|%.6f|%.6f|%d|%.6f|%.6f|%d|%.6f|%d|%d\n",
            v->placa, v->marca, v->modelo, v->tipoCombustible,
            v->kmxGalonCarretera, v->kmxGalonCiudad,
            v->costoGomas, v->kmGomas,
            v->costoSeguroAnual, v->costoMantenimiento, v->kmMantenimiento,
            v->costoVehiculo, v->vidaUtil, v->kmAnuales
        );
    }
    fclose(f);
    return 1;
}

int cargarVehiculos() {
    FILE *f = fopen(FILE_VEH, "r");
    if (!f) return 0; // no es error, puede no existir la primera vez
    totalVehiculos = 0;

    while (!feof(f) && totalVehiculos < MAX) {
        Vehiculo v;
        int read = fscanf(
            f,
            " %14[^|]|%19[^|]|%19[^|]|%9[^|]|%f|%f|%f|%d|%f|%f|%d|%f|%d|%d",
            v.placa, v.marca, v.modelo, v.tipoCombustible,
            &v.kmxGalonCarretera, &v.kmxGalonCiudad,
            &v.costoGomas, &v.kmGomas,
            &v.costoSeguroAnual, &v.costoMantenimiento, &v.kmMantenimiento,
            &v.costoVehiculo, &v.vidaUtil, &v.kmAnuales
        );
        if (read == 14) {
            vehiculos[totalVehiculos++] = v;
        }
        // consumir fin de linea si queda
        int ch;
        while ((ch = fgetc(f)) != '\n' && ch != EOF) {}
    }

    fclose(f);
    return 1;
}

int guardarConfig() {
    FILE *f = fopen(FILE_CFG, "w");
    if (!f) return 0;
    // dos lineas: gasolina y gasoil
    fprintf(f, "%.6f\n%.6f\n", costoGasolina, costoGasoil);
    fclose(f);
    return 1;
}

int cargarConfig() {
    FILE *f = fopen(FILE_CFG, "r");
    if (!f) return 0;
    float g1, g2;
    int ok = fscanf(f, "%f%f", &g1, &g2);
    fclose(f);
    if (ok == 2) {
        costoGasolina = g1;
        costoGasoil   = g2;
        return 1;
    }
    return 0;
}

// ---------- utilidades ----------
void listarVehiculos() {
    if (totalVehiculos == 0) {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    printf("\n--- Lista de vehiculos (%d) ---\n", totalVehiculos);
    for (int i = 0; i < totalVehiculos; i++) {
        printf("[%d] %s - %s %s (%s)\n",
            i, vehiculos[i].placa, vehiculos[i].marca,
            vehiculos[i].modelo, vehiculos[i].tipoCombustible);
    }
}

int buscarIndicePorPlaca(const char *placa) {
    for (int i = 0; i < totalVehiculos; i++) {
        if (strcmp(vehiculos[i].placa, placa) == 0) return i;
    }
    return -1;
}

// ---------- CRUD vehiculos ----------
void crearVehiculo() {
    if (totalVehiculos >= MAX) {
        printf("No se pueden agregar mas vehiculos.\n");
        return;
    }

    Vehiculo v;
    char buf[128];

    printf("Placa (sin espacios): ");
    leerLinea(buf, sizeof(buf)); strncpy(v.placa, buf, sizeof(v.placa)); v.placa[sizeof(v.placa)-1] = '\0';

    if (buscarIndicePorPlaca(v.placa) != -1) {
        printf("Ya existe un vehiculo con esa placa.\n");
        return;
    }

    printf("Marca: ");  leerLinea(buf, sizeof(buf)); strncpy(v.marca, buf, sizeof(v.marca)); v.marca[sizeof(v.marca)-1] = '\0';
    printf("Modelo: "); leerLinea(buf, sizeof(buf)); strncpy(v.modelo, buf, sizeof(v.modelo)); v.modelo[sizeof(v.modelo)-1] = '\0';
    printf("Tipo de combustible (Gasolina/Gasoil): ");
    leerLinea(buf, sizeof(buf)); strncpy(v.tipoCombustible, buf, sizeof(v.tipoCombustible)); v.tipoCombustible[sizeof(v.tipoCombustible)-1] = '\0';

    printf("Km por galon carretera: "); scanf("%f", &v.kmxGalonCarretera);
    printf("Km por galon ciudad: ");    scanf("%f", &v.kmxGalonCiudad);
    printf("Costo total gomas: ");      scanf("%f", &v.costoGomas);
    printf("Km de vida de las gomas: ");scanf("%d", &v.kmGomas);
    printf("Costo del seguro anual: "); scanf("%f", &v.costoSeguroAnual);
    printf("Costo mantenimiento: ");    scanf("%f", &v.costoMantenimiento);
    printf("Cada cuantos km se hace mantenimiento: "); scanf("%d", &v.kmMantenimiento);
    printf("Costo del vehiculo: ");     scanf("%f", &v.costoVehiculo);
    printf("Vida util del vehiculo (anios): "); scanf("%d", &v.vidaUtil);
    printf("Promedio km por agno: ");   scanf("%d", &v.kmAnuales);
    // limpiar \n pendiente
    int c; while ((c = getchar()) != '\n' && c != EOF) {}

    vehiculos[totalVehiculos++] = v;
    guardarVehiculos();
    printf("Vehiculo creado y guardado.\n");
}

void borrarVehiculo() {
    if (totalVehiculos == 0) {
        printf("No hay vehiculos para borrar.\n");
        return;
    }
    listarVehiculos();
    printf("Ingrese el indice del vehiculo a borrar: ");
    int index; scanf("%d", &index);
    int c; while ((c = getchar()) != '\n' && c != EOF) {}

    if (index < 0 || index >= totalVehiculos) {
        printf("Indice invalido.\n");
        return;
    }
    for (int i = index; i < totalVehiculos - 1; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    totalVehiculos--;
    guardarVehiculos();
    printf("Vehiculo borrado y cambios guardados.\n");
}

void modificarVehiculo() {
    if (totalVehiculos == 0) {
        printf("No hay vehiculos para modificar.\n");
        return;
    }
    listarVehiculos();
    printf("Ingrese el indice del vehiculo a modificar: ");
    int index; scanf("%d", &index);
    int c; while ((c = getchar()) != '\n' && c != EOF) {}

    if (index < 0 || index >= totalVehiculos) {
        printf("Indice invalido.\n");
        return;
    }

    Vehiculo *v = &vehiculos[index];
    char buf[128];

    printf("Nueva placa (%s): ", v->placa); leerLinea(buf, sizeof(buf)); if(strlen(buf)) { strncpy(v->placa, buf, sizeof(v->placa)); v->placa[sizeof(v->placa)-1]='\0'; }
    printf("Nueva marca (%s): ", v->marca); leerLinea(buf, sizeof(buf)); if(strlen(buf)) { strncpy(v->marca, buf, sizeof(v->marca)); v->marca[sizeof(v->marca)-1]='\0'; }
    printf("Nuevo modelo (%s): ", v->modelo); leerLinea(buf, sizeof(buf)); if(strlen(buf)) { strncpy(v->modelo, buf, sizeof(v->modelo)); v->modelo[sizeof(v->modelo)-1]='\0'; }
    printf("Tipo combustible (%s): ", v->tipoCombustible); leerLinea(buf, sizeof(buf)); if(strlen(buf)) { strncpy(v->tipoCombustible, buf, sizeof(v->tipoCombustible)); v->tipoCombustible[sizeof(v->tipoCombustible)-1]='\0'; }

    printf("Km por galon carretera (%.2f): ", v->kmxGalonCarretera); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->kmxGalonCarretera = strtof(buf, NULL);
    printf("Km por galon ciudad (%.2f): ", v->kmxGalonCiudad); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->kmxGalonCiudad = strtof(buf, NULL);
    printf("Costo total gomas (%.2f): ", v->costoGomas); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->costoGomas = strtof(buf, NULL);
    printf("Km vida gomas (%d): ", v->kmGomas); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->kmGomas = (int)strtol(buf, NULL, 10);
    printf("Costo seguro anual (%.2f): ", v->costoSeguroAnual); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->costoSeguroAnual = strtof(buf, NULL);
    printf("Costo mantenimiento (%.2f): ", v->costoMantenimiento); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->costoMantenimiento = strtof(buf, NULL);
    printf("Km mantenimiento (%d): ", v->kmMantenimiento); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->kmMantenimiento = (int)strtol(buf, NULL, 10);
    printf("Costo vehiculo (%.2f): ", v->costoVehiculo); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->costoVehiculo = strtof(buf, NULL);
    printf("Vida util (anios) (%d): ", v->vidaUtil); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->vidaUtil = (int)strtol(buf, NULL, 10);
    printf("Km anuales promedio (%d): ", v->kmAnuales); fgets(buf, sizeof(buf), stdin); if(strlen(buf)>1) v->kmAnuales = (int)strtol(buf, NULL, 10);

    guardarVehiculos();
    printf("Vehiculo modificado y guardado.\n");
}

// ---------- configuracion general ----------
void configurarCostosGenerales() {
    printf("Costo por galon de gasolina (actual %.2f): ", costoGasolina);
    scanf("%f", &costoGasolina);
    printf("Costo por galon de gasoil (actual %.2f): ", costoGasoil);
    scanf("%f", &costoGasoil);
    int c; while ((c = getchar()) != '\n' && c != EOF) {}
    guardarConfig();
    printf("Configuracion guardada.\n");
}

// ---------- calculo de viaje ----------
void calcularCostoViaje() {
    if (totalVehiculos == 0) {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    if (costoGasolina <= 0 && costoGasoil <= 0) {
        printf("Primero configure los costos de combustibles.\n");
        return;
    }

    listarVehiculos();
    printf("Seleccione el indice del vehiculo: ");
    int index; scanf("%d", &index);
    int c; while ((c = getchar()) != '\n' && c != EOF) {}

    if (index < 0 || index >= totalVehiculos) {
        printf("Indice invalido.\n");
        return;
    }

    Vehiculo v = vehiculos[index];

    float distancia, porcentajeCiudad;
    printf("Distancia total del viaje (km): "); scanf("%f", &distancia);
    printf("Porcentaje en ciudad (0-100): ");   scanf("%f", &porcentajeCiudad);
    while ((c = getchar()) != '\n' && c != EOF) {}

    if (distancia <= 0) {
        printf("La distancia debe ser mayor que 0.\n");
        return;
    }
    if (porcentajeCiudad < 0) porcentajeCiudad = 0;
    if (porcentajeCiudad > 100) porcentajeCiudad = 100;

    float kmCiudad    = distancia * (porcentajeCiudad / 100.0f);
    float kmCarretera = distancia - kmCiudad;

    float galonesCiudad    = (v.kmxGalonCiudad    > 0) ? (kmCiudad    / v.kmxGalonCiudad)    : 0.0f;
    float galonesCarretera = (v.kmxGalonCarretera > 0) ? (kmCarretera / v.kmxGalonCarretera) : 0.0f;
    float totalGalones = galonesCiudad + galonesCarretera;

    float precioComb = (strcmp(v.tipoCombustible, "Gasolina") == 0) ? costoGasolina : costoGasoil;
    float costoCombustible = totalGalones * precioComb;

    float costoGomasKm = (v.kmGomas > 0) ? (v.costoGomas / v.kmGomas) : 0.0f;
    float costoGomas   = costoGomasKm * distancia;

    float seguroPorKm  = (v.kmAnuales > 0) ? (v.costoSeguroAnual / v.kmAnuales) : 0.0f;
    float costoSeguro  = seguroPorKm * distancia;

    float mantPorKm    = (v.kmMantenimiento > 0) ? (v.costoMantenimiento / v.kmMantenimiento) : 0.0f;
    float costoMantenimiento = mantPorKm * distancia;

    float depPorKm = (v.kmAnuales > 0 && v.vidaUtil > 0) ? (v.costoVehiculo / (v.kmAnuales * v.vidaUtil)) : 0.0f;
    float depreciacion = depPorKm * distancia;

    float costoTotal = costoCombustible + costoGomas + costoSeguro + costoMantenimiento + depreciacion;
    float costoPorKm = costoTotal / distancia;

    printf("\n--- Desglose del costo del viaje ---\n");
    printf("Vehiculo: %s %s %s (%s)\n", v.placa, v.marca, v.modelo, v.tipoCombustible);
    printf("Combustible: %.2f\n", costoCombustible);
    printf("Gomas: %.2f\n", costoGomas);
    printf("Seguro: %.2f\n", costoSeguro);
    printf("Mantenimiento: %.2f\n", costoMantenimiento);
    printf("Depreciacion vehiculo: %.2f\n", depreciacion);
    printf("Costo total del viaje: %.2f\n", costoTotal);
    printf("Costo por km: %.4f\n", costoPorKm);
}

// ---------- menu ----------
void menu() {
    int opcion;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Crear vehiculo\n");
        printf("2. Listar vehiculos\n");
        printf("3. Borrar vehiculo\n");
        printf("4. Modificar vehiculo\n");
        printf("5. Configurar costos generales\n");
        printf("6. Calcular costo de viaje\n");
        printf("7. Guardar todo\n");
        printf("8. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            // limpiar entrada incorrecta
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            opcion = 0;
        }
        int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}

        switch (opcion) {
            case 1: crearVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: borrarVehiculo(); break;
            case 4: modificarVehiculo(); break;
            case 5: configurarCostosGenerales(); break;
            case 6: calcularCostoViaje(); break;
            case 7:
                if (guardarVehiculos() && guardarConfig())
                    printf("Datos guardados.\n");
                else
                    printf("Error al guardar.\n");
                break;
            case 8:
                // guardado automatico al salir
                if (guardarVehiculos() && guardarConfig())
                    printf("Guardado final correcto. Saliendo...\n");
                else
                    printf("Saliendo (no se pudo guardar todo).\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 8);
}

int main() {
    // cargar datos al inicio (si existen)
    if (cargarVehiculos())
        printf("Vehiculos cargados: %d\n", totalVehiculos);
    else
        printf("No se cargaron vehiculos (posible primera ejecucion).\n");

    if (cargarConfig())
        printf("Config cargada. Gasolina=%.2f, Gasoil=%.2f\n", costoGasolina, costoGasoil);
    else
        printf("No se cargo config. Configure costos generales.\n");

    menu();
    return 0;
}
