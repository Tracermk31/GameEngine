#pragma once
#include <cstdint>

namespace ChiefEngine {
	class Time {
	public:
		Time();

		void Reset();
		void Tick();

		inline float getTime() const { return TicksToSeconds(m_currentTicks - m_startTicks); }
		inline float getDeltaTime() const { return TicksToSeconds(m_deltaTicks); }

		inline float TicksToSeconds(uint64_t ticks) const { return ticks / 1'000'000'000.0f; }
	private:
		uint64_t m_startTicks = 0;
		uint64_t m_currentTicks = 0;
		uint64_t m_frameTicks = 0;
		uint64_t m_deltaTicks = 0;
	};
}