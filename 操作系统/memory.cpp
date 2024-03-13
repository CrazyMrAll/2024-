#include <Windows.h>
#include <psapi.h>
#include <iostream>

void DisplaySystemMemoryInfo() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    std::cout << "System Memory Information:" << std::endl;
    std::cout << "Page Size: " << sysInfo.dwPageSize << " bytes" << std::endl;
    std::cout << "Allocation Granularity: " << sysInfo.dwAllocationGranularity << " bytes" << std::endl;

    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);

    if (GlobalMemoryStatusEx(&memoryStatus)) {
        std::cout << "Total Physical Memory: " << memoryStatus.ullTotalPhys << " bytes" << std::endl;
        std::cout << "Available Physical Memory: " << memoryStatus.ullAvailPhys << " bytes" << std::endl;
        std::cout << "Total Virtual Memory: " << memoryStatus.ullTotalVirtual << " bytes" << std::endl;
        std::cout << "Available Virtual Memory: " << memoryStatus.ullAvailVirtual << " bytes" << std::endl;
    } else {
        std::cout << "Failed to get memory status" << std::endl;
    }
}

void DisplayProcessMemoryInfo() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        std::cout << "\nProcess Memory Information:" << std::endl;
        std::cout << "Working Set Size: " << pmc.WorkingSetSize << " bytes" << std::endl;
        std::cout << "Private Bytes: " << pmc.PrivateUsage << " bytes" << std::endl;
        std::cout << "Pagefile Usage: " << pmc.PagefileUsage << " bytes" << std::endl;
    } else {
        std::cout << "Failed to get process memory info" << std::endl;
    }
}

void DisplayVirtualAddressSpaceLayout() {
    LPVOID address = 0;
    MEMORY_BASIC_INFORMATION memInfo;

    std::cout << "\nVirtual Address Space Layout:" << std::endl;
    while (VirtualQueryEx(GetCurrentProcess(), address, &memInfo, sizeof(memInfo))) {
        std::cout << "Base Address: " << memInfo.BaseAddress << std::endl;
        std::cout << "Region Size: " << memInfo.RegionSize << std::endl;
        std::cout << "State: " << memInfo.State << std::endl;
        std::cout << "Type: " << memInfo.Type << std::endl;

        address = LPVOID((char*)memInfo.BaseAddress + memInfo.RegionSize);
    }
}

int main() {
    DisplaySystemMemoryInfo();
    DisplayProcessMemoryInfo();
    DisplayVirtualAddressSpaceLayout();
    return 0;
}
