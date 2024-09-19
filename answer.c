#include <stdio.h>
#include <math.h>

int main() {
    double ve;          // 유효 배기 속도 (m/s)
    double h;           // 목표 궤도 높이 (m)
    double delta_v;     // 필요한 총 속도 변화량 (m/s)
    double m0;          // 초기 총 질량 (연료 포함) (kg)
    double mf;          // 최종 총 질량 (연료 소모 후) (kg)
    double m_fuel;      // 필요한 연료 무게 (kg)
    double orbital_velocity; // 궤도 속도 (m/s)
    double gravity_losses;   // 중력 손실 (m/s)
    double drag_losses;      // 대기 저항 손실 (m/s)

    scanf("%lf %lf %lf", &ve, &h, &m0);

    // 지구 반지름 (m)
    const double earth_radius = 6371000;

    // 목표 궤도 반지름
    double orbit_radius = earth_radius + h;

    // 궤도 속도 계산
    const double mu = 3.986004418e14; // 지구 중력 상수 (m^3/s^2)
    orbital_velocity = sqrt(mu / orbit_radius);

    // 중력 손실 및 대기 저항 손실 (평균 값 사용)
    gravity_losses = 1500; // 중력 손실 (m/s)
    drag_losses = 200;     // 대기 저항 손실 (m/s)

    // 필요한 총 Δv 계산
    delta_v = orbital_velocity + gravity_losses + drag_losses;

    // 최종 총 질량 계산 (치올콥스키 로켓 방정식 활용)
    mf = m0 * exp(-delta_v / ve);

    // 필요한 연료 무게 계산
    m_fuel = m0 - mf;

    printf("%.2f", m_fuel);

    return 0;
}
