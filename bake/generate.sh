#!/bin/sh

set -e

cd "$(dirname "$0")"

npm run build

mkdir -p generated

node dist/index.js ps_hardcoded_tst 1 tst > generated/ps_hardcoded_tst_1.c.txt
node dist/index.js ps_hardcoded_tsb 1 tsb > generated/ps_hardcoded_tsb_1.c.txt
node dist/index.js ps_hardcoded_txt 1 txt > generated/ps_hardcoded_txt_1.c.txt
node dist/index.js ps_hardcoded_txb 1 txb > generated/ps_hardcoded_txb_1.c.txt
node dist/index.js ps_hardcoded_tot 1 tot > generated/ps_hardcoded_tot_1.c.txt
node dist/index.js ps_hardcoded_tos 1 tos > generated/ps_hardcoded_tos_1.c.txt
node dist/index.js ps_hardcoded_tob 1 tob > generated/ps_hardcoded_tob_1.c.txt
node dist/index.js ps_hardcoded_sss 1 sss > generated/ps_hardcoded_sss_1.c.txt
node dist/index.js ps_hardcoded_sxs 1 sxs > generated/ps_hardcoded_sxs_1.c.txt
node dist/index.js ps_hardcoded_sot 1 sot > generated/ps_hardcoded_sot_1.c.txt
node dist/index.js ps_hardcoded_sos 1 sos > generated/ps_hardcoded_sos_1.c.txt
node dist/index.js ps_hardcoded_sob 1 sob > generated/ps_hardcoded_sob_1.c.txt
node dist/index.js ps_hardcoded_bst 1 bst > generated/ps_hardcoded_bst_1.c.txt
node dist/index.js ps_hardcoded_bsb 1 bsb > generated/ps_hardcoded_bsb_1.c.txt
node dist/index.js ps_hardcoded_bxt 1 bxt > generated/ps_hardcoded_bxt_1.c.txt
node dist/index.js ps_hardcoded_bxb 1 bxb > generated/ps_hardcoded_bxb_1.c.txt
node dist/index.js ps_hardcoded_bot 1 bot > generated/ps_hardcoded_bot_1.c.txt
node dist/index.js ps_hardcoded_bos 1 bos > generated/ps_hardcoded_bos_1.c.txt
node dist/index.js ps_hardcoded_bob 1 bob > generated/ps_hardcoded_bob_1.c.txt
