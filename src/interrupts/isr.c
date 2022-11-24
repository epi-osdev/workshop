#include "utils/VGA.h"
#include "idt.h"
#include "isr.h"
#include "pic.h"

isr_callback isr_handlers[ENTRIES_NUM];

static void isr_init_idt_gates()
{
    // The segment selector is 0x08 because it refers to the kernel code segment
    set_idt_gate(0, isr0, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(1, isr1, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(2, isr2, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(3, isr3, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(4, isr4, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(5, isr5, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(6, isr6, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(7, isr7, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(8, isr8, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(9, isr9, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(10, isr10, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(11, isr11, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(12, isr12, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(13, isr13, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(14, isr14, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(15, isr15, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(16, isr16, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(17, isr17, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(18, isr18, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(19, isr19, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(20, isr20, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(21, isr21, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(22, isr22, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(23, isr23, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(24, isr24, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(25, isr25, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(26, isr26, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(27, isr27, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(28, isr28, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(29, isr29, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(30, isr30, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(31, isr31, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(32, isr32, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(33, isr33, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(34, isr34, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(35, isr35, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(36, isr36, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(37, isr37, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(38, isr38, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(39, isr39, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(40, isr40, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(41, isr41, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(42, isr42, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(43, isr43, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(44, isr44, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(45, isr45, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(46, isr46, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(47, isr47, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(48, isr48, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(49, isr49, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(50, isr50, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(51, isr51, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(52, isr52, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(53, isr53, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(54, isr54, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(55, isr55, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(56, isr56, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(57, isr57, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(58, isr58, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(59, isr59, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(60, isr60, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(61, isr61, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(62, isr62, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(63, isr63, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(64, isr64, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(65, isr65, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(66, isr66, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(67, isr67, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(68, isr68, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(69, isr69, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(70, isr70, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(71, isr71, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(72, isr72, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(73, isr73, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(74, isr74, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(75, isr75, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(76, isr76, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(77, isr77, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(78, isr78, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(79, isr79, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(80, isr80, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(81, isr81, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(82, isr82, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(83, isr83, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(84, isr84, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(85, isr85, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(86, isr86, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(87, isr87, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(88, isr88, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(89, isr89, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(90, isr90, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(91, isr91, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(92, isr92, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(93, isr93, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(94, isr94, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(95, isr95, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(96, isr96, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(97, isr97, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(98, isr98, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(99, isr99, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(100, isr100, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(101, isr101, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(102, isr102, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(103, isr103, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(104, isr104, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(105, isr105, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(106, isr106, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(107, isr107, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(108, isr108, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(109, isr109, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(110, isr110, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(111, isr111, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(112, isr112, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(113, isr113, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(114, isr114, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(115, isr115, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(116, isr116, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(117, isr117, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(118, isr118, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(119, isr119, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(120, isr120, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(121, isr121, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(122, isr122, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(123, isr123, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(124, isr124, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(125, isr125, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(126, isr126, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(127, isr127, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(128, isr128, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(129, isr129, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(130, isr130, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(131, isr131, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(132, isr132, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(133, isr133, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(134, isr134, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(135, isr135, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(136, isr136, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(137, isr137, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(138, isr138, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(139, isr139, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(140, isr140, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(141, isr141, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(142, isr142, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(143, isr143, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(144, isr144, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(145, isr145, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(146, isr146, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(147, isr147, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(148, isr148, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(149, isr149, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(150, isr150, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(151, isr151, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(152, isr152, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(153, isr153, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(154, isr154, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(155, isr155, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(156, isr156, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(157, isr157, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(158, isr158, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(159, isr159, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(160, isr160, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(161, isr161, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(162, isr162, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(163, isr163, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(164, isr164, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(165, isr165, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(166, isr166, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(167, isr167, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(168, isr168, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(169, isr169, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(170, isr170, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(171, isr171, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(172, isr172, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(173, isr173, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(174, isr174, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(175, isr175, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(176, isr176, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(177, isr177, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(178, isr178, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(179, isr179, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(180, isr180, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(181, isr181, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(182, isr182, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(183, isr183, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(184, isr184, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(185, isr185, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(186, isr186, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(187, isr187, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(188, isr188, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(189, isr189, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(190, isr190, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(191, isr191, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(192, isr192, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(193, isr193, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(194, isr194, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(195, isr195, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(196, isr196, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(197, isr197, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(198, isr198, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(199, isr199, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(200, isr200, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(201, isr201, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(202, isr202, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(203, isr203, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(204, isr204, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(205, isr205, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(206, isr206, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(207, isr207, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(208, isr208, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(209, isr209, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(210, isr210, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(211, isr211, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(212, isr212, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(213, isr213, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(214, isr214, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(215, isr215, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(216, isr216, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(217, isr217, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(218, isr218, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(219, isr219, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(220, isr220, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(221, isr221, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(222, isr222, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(223, isr223, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(224, isr224, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(225, isr225, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(226, isr226, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(227, isr227, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(228, isr228, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(229, isr229, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(230, isr230, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(231, isr231, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(232, isr232, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(233, isr233, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(234, isr234, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(235, isr235, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(236, isr236, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(237, isr237, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(238, isr238, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(239, isr239, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(240, isr240, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(241, isr241, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(242, isr242, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(243, isr243, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(244, isr244, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(245, isr245, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(246, isr246, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(247, isr247, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(248, isr248, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(249, isr249, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(250, isr250, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(251, isr251, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(252, isr252, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(253, isr253, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(254, isr254, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    set_idt_gate(255, isr255, 0x08, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
}

void isr_init()
{
    isr_init_idt_gates();
    idt_enable_gates();
    // pic_remap();

    unset_gate_flag(0x80, IDT_FLAG_PRESENT);
}

void isr_handler(registers_t *regs)
{
    uint32_t interrupt = regs->interrupt;

    if (isr_handlers[interrupt] != 0) {
        isr_handlers[interrupt](regs);
    } else if (interrupt >= 32) {
        // not handled
    } else {
        // exception isr
    }

    vga_putchar_at('B', 0xce, 10, 10);
}

void isr_register_handler(int interrupt, isr_callback callback)
{
    isr_handlers[interrupt] = callback;
    set_gate_flag(interrupt, IDT_FLAG_PRESENT);
}
