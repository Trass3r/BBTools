auto file, fname, i, address, size;
size = 0x900;
address = 0x00559B60 + size * 1;
fname = "dump_mem.bin";
file = fopen(fname, "wb");
for (i = 0; i < size; i++, address++)
  fputc(DbgByte(address), file);
fclose(file);
