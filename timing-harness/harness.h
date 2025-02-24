#ifndef HARNESS_H
#define HARNESS_H

#define HARNESS_ITERS 16

// use this to create a shm fd for measurement
int create_shm_fd(char *path);

struct pmc_counters {
  uint64_t core_cyc;
  uint64_t l1_read_misses;
  uint64_t icache_misses;
  uint64_t tlb_write_misses;
  uint64_t tlb_read_misses;
  uint64_t context_switches;
};

struct pmc_counters *measure(
    char *code_to_test,
    unsigned long code_size,
    unsigned int unroll_factor,
    char *code_init,
    unsigned long code_init_size,
    int *l1_read_supported,
    int *icache_supported,
    int *llb_write_supported,
    int *tlb_read_supported,
    int shm_fd);

#endif // HARNESS_H
