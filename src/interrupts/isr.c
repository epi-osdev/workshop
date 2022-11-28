#include "utils/VGA.h"
#include "idt.h"
#include "isr.h"
#include "pic.h"

isr_callback isr_handlers[ENTRIES_NUM];

static void isr_init_idt_gates()
{
    set_idt_gate(0, isr0, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(1, isr1, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(2, isr2, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(3, isr3, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(4, isr4, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(5, isr5, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(6, isr6, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(7, isr7, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(8, isr8, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(9, isr9, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(10, isr10, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(11, isr11, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(12, isr12, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(13, isr13, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(14, isr14, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(15, isr15, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(16, isr16, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(17, isr17, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(18, isr18, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(19, isr19, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(20, isr20, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(21, isr21, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(22, isr22, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(23, isr23, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(24, isr24, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(25, isr25, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(26, isr26, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(27, isr27, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(28, isr28, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(29, isr29, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(30, isr30, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(31, isr31, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(32, isr32, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(33, isr33, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(34, isr34, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(35, isr35, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(36, isr36, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(37, isr37, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(38, isr38, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(39, isr39, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(40, isr40, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(41, isr41, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(42, isr42, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(43, isr43, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(44, isr44, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(45, isr45, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(46, isr46, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(47, isr47, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(48, isr48, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(49, isr49, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(50, isr50, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(51, isr51, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(52, isr52, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(53, isr53, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(54, isr54, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(55, isr55, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(56, isr56, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(57, isr57, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(58, isr58, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(59, isr59, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(60, isr60, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(61, isr61, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(62, isr62, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(63, isr63, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(64, isr64, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(65, isr65, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(66, isr66, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(67, isr67, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(68, isr68, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(69, isr69, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(70, isr70, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(71, isr71, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(72, isr72, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(73, isr73, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(74, isr74, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(75, isr75, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(76, isr76, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(77, isr77, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(78, isr78, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(79, isr79, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(80, isr80, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(81, isr81, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(82, isr82, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(83, isr83, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(84, isr84, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(85, isr85, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(86, isr86, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(87, isr87, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(88, isr88, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(89, isr89, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(90, isr90, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(91, isr91, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(92, isr92, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(93, isr93, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(94, isr94, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(95, isr95, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(96, isr96, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(97, isr97, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(98, isr98, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(99, isr99, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(100, isr100, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(101, isr101, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(102, isr102, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(103, isr103, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(104, isr104, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(105, isr105, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(106, isr106, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(107, isr107, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(108, isr108, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(109, isr109, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(110, isr110, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(111, isr111, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(112, isr112, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(113, isr113, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(114, isr114, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(115, isr115, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(116, isr116, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(117, isr117, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(118, isr118, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(119, isr119, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(120, isr120, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(121, isr121, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(122, isr122, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(123, isr123, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(124, isr124, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(125, isr125, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(126, isr126, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(127, isr127, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(128, isr128, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(129, isr129, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(130, isr130, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(131, isr131, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(132, isr132, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(133, isr133, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(134, isr134, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(135, isr135, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(136, isr136, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(137, isr137, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(138, isr138, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(139, isr139, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(140, isr140, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(141, isr141, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(142, isr142, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(143, isr143, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(144, isr144, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(145, isr145, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(146, isr146, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(147, isr147, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(148, isr148, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(149, isr149, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(150, isr150, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(151, isr151, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(152, isr152, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(153, isr153, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(154, isr154, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(155, isr155, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(156, isr156, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(157, isr157, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(158, isr158, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(159, isr159, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(160, isr160, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(161, isr161, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(162, isr162, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(163, isr163, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(164, isr164, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(165, isr165, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(166, isr166, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(167, isr167, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(168, isr168, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(169, isr169, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(170, isr170, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(171, isr171, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(172, isr172, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(173, isr173, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(174, isr174, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(175, isr175, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(176, isr176, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(177, isr177, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(178, isr178, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(179, isr179, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(180, isr180, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(181, isr181, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(182, isr182, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(183, isr183, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(184, isr184, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(185, isr185, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(186, isr186, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(187, isr187, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(188, isr188, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(189, isr189, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(190, isr190, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(191, isr191, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(192, isr192, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(193, isr193, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(194, isr194, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(195, isr195, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(196, isr196, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(197, isr197, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(198, isr198, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(199, isr199, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(200, isr200, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(201, isr201, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(202, isr202, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(203, isr203, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(204, isr204, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(205, isr205, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(206, isr206, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(207, isr207, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(208, isr208, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(209, isr209, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(210, isr210, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(211, isr211, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(212, isr212, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(213, isr213, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(214, isr214, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(215, isr215, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(216, isr216, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(217, isr217, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(218, isr218, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(219, isr219, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(220, isr220, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(221, isr221, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(222, isr222, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(223, isr223, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(224, isr224, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(225, isr225, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(226, isr226, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(227, isr227, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(228, isr228, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(229, isr229, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(230, isr230, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(231, isr231, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(232, isr232, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(233, isr233, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(234, isr234, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(235, isr235, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(236, isr236, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(237, isr237, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(238, isr238, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(239, isr239, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(240, isr240, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(241, isr241, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(242, isr242, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(243, isr243, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(244, isr244, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(245, isr245, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(246, isr246, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(247, isr247, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(248, isr248, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(249, isr249, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(250, isr250, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(251, isr251, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(252, isr252, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(253, isr253, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(254, isr254, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(255, isr255, KERNEL_CODE_SEG, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
}

void isr_init()
{
    isr_init_idt_gates();
    idt_enable_gates();
    pic_remap();

    // unset_gate_flag(0x80, IDT_FLAG_PRESENT);
}

void isr_handler(registers_t *regs)
{
    uint32_t interrupt = regs->interrupt;
    static size_t y = 0;

    if (isr_handlers[interrupt] != 0) {
        isr_handlers[interrupt](regs);
    } else if (interrupt >= 32) {
        
    } else {
        // exception isr
    }

    vga_print_int_at(interrupt, 0xce, 0, y++);
}

void isr_register_handler(int interrupt, isr_callback callback)
{
    isr_handlers[interrupt] = callback;
    set_gate_flag(interrupt, IDT_FLAG_PRESENT);
}

void irq_handler(registers_t *regs)
{
    if (regs->interrupt >= 40) { // After every interrupt we need to send an EOI to the PICs or they will not send another interrupt again
        port_byte_out(0xa0, 0x20); // Slave
    }

    port_byte_out(0x20, 0x20); // Master

    if (isr_handlers[regs->interrupt] != 0) {  // Handle the interrupt in a more modular way
        isr_handlers[regs->interrupt](regs);
    }
}
