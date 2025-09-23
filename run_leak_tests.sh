#!/bin/bash
# filepath: c:\Users\Usuario\Desktop\42\CURSUS\THIRD CIRCLE\PUSH_SWAP\push_swap\run_leak_tests.sh

echo "🔍 INICIANDO PRUEBAS DE MEMORY LEAKS PARA PUSH_SWAP"
echo "=================================================="

# Compilar proyecto
echo "📦 Compilando proyecto..."
make clean && make
if [ $? -ne 0 ]; then
    echo "❌ Error en compilación"
    exit 1
fi

# Contador de pruebas
test_count=0
passed_tests=0

# Función para ejecutar test
run_test() {
    local test_name="$1"
    local test_cmd="$2"
    
    ((test_count++))
    echo ""
    echo "🧪 Test $test_count: $test_name"
    echo "Comando: $test_cmd"
    
    # Ejecutar valgrind y capturar resultado
    valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 $test_cmd 2>&1)
    exit_code=$?
    
    # Verificar si hay leaks
    if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo "✅ PASSED - Sin memory leaks"
        ((passed_tests++))
    elif echo "$valgrind_output" | grep -q "definitely lost\|possibly lost\|still reachable"; then
        echo "❌ FAILED - Memory leaks detectados:"
        echo "$valgrind_output" | grep -E "(definitely lost|possibly lost|still reachable)"
    else
        echo "⚠️  WARNING - Resultado indeterminado"
        echo "$valgrind_output" | tail -5
    fi
}

echo ""
echo "🔥 EJECUTANDO PRUEBAS BÁSICAS..."
echo "================================"

# CASOS BÁSICOS
run_test "Números simples" "./push_swap 3 2 1 5 4"
run_test "Ya ordenado" "./push_swap 1 2 3 4 5"
run_test "Orden inverso" "./push_swap 5 4 3 2 1"
run_test "Un elemento" "./push_swap 42"
run_test "Dos elementos" "./push_swap 2 1"
run_test "Tres elementos" "./push_swap 3 1 2"

echo ""
echo "🎯 EJECUTANDO CASOS EDGE..."
echo "==========================="

# CASOS EDGE
run_test "Valores extremos" "./push_swap 2147483647 -2147483648 0"
run_test "Números negativos" "./push_swap -1 -2 -3"
run_test "Sin argumentos" "./push_swap"

echo ""
echo "⚠️  EJECUTANDO CASOS DE ERROR..."
echo "================================"

# CASOS DE ERROR
run_test "Duplicados" "./push_swap 1 2 1"
run_test "No números" "./push_swap abc 123"
run_test "Overflow" "./push_swap 2147483648"
run_test "Underflow" "./push_swap -2147483649"
run_test "String vacío" "./push_swap \"\""

echo ""
echo "📝 EJECUTANDO CASOS CON ESPACIOS..."
echo "==================================="

# CASOS CON ESPACIOS
run_test "Con espacios 1" "./push_swap \"3 2 1\" \"5 4\""
run_test "Con espacios 2" "./push_swap \"1 2 3 4 5\""
run_test "Argumentos mixtos" "./push_swap \"5\" \"4\" \"3\" \"2\" \"1\""

echo ""
echo "💪 EJECUTANDO STRESS TESTS..."
echo "============================="

# STRESS TESTS
run_test "10 elementos aleatorios" "./push_swap 1 5 2 4 3 8 6 7 10 9"
run_test "10 elementos inversos" "./push_swap 10 9 8 7 6 5 4 3 2 1"
run_test "10 elementos mezclados" "./push_swap 1 3 5 7 9 2 4 6 8 10"

echo ""
echo "🔥 EJECUTANDO STRESS TEST MASIVO..."
echo "==================================="

# Stress test de 100 iteraciones
stress_passed=0
for i in {1..100}; do
    valgrind --leak-check=full --error-exitcode=1 ./push_swap 3 2 1 5 4 >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        ((stress_passed++))
    fi
    if [ $((i % 25)) -eq 0 ]; then
        echo "🔄 Completadas $i/100 iteraciones - Exitosas: $stress_passed"
    fi
done

echo ""
echo "📊 RESUMEN DE RESULTADOS"
echo "======================="
echo "Pruebas individuales: $passed_tests/$test_count"
echo "Stress test: $stress_passed/100"
echo ""

if [ $passed_tests -eq $test_count ] && [ $stress_passed -eq 100 ]; then
    echo "🎉 ¡FELICIDADES! Tu proyecto está perfecto:"
    echo "   ✅ Todas las pruebas individuales pasaron"
    echo "   ✅ 100/100 iteraciones del stress test exitosas"
    echo "   ✅ Sin memory leaks detectados"
    echo ""
    echo "🚀 Tu push_swap está listo para la evaluación!"
elif [ $passed_tests -eq $test_count ]; then
    echo "✅ Todas las pruebas individuales pasaron"
    echo "⚠️  Algunas iteraciones del stress test fallaron ($stress_passed/100)"
    echo "   Esto podría indicar memory leaks intermitentes"
else
    echo "❌ Algunas pruebas fallaron:"
    echo "   Individuales: $passed_tests/$test_count"
    echo "   Stress test: $stress_passed/100"
    echo ""
    echo "🔧 Revisa los memory leaks reportados arriba"
fi

echo ""
echo "💡 TIPS:"
echo "   - 'All heap blocks were freed' = ✅ Sin leaks"
echo "   - 'definitely lost' = ❌ Memory leaks críticos"
echo "   - 'possibly lost' = ⚠️  Posibles memory leaks"