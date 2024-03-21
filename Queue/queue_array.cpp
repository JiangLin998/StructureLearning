/**
  ******************************************************************************
  * @file           : queue_array.cpp
  * @author         : Troy
  * @brief          : None
  * @attention      : None
  * @date           : 2024/3/16
  ******************************************************************************
  */
#include <cstdlib>
#include <iostream>
#include "queue_array.h"

/**
 * @brief �ж϶����Ƿ�Ϊ��
 * @param q ����ָ��
 * @return 1Ϊ�� 0Ϊ�ǿ�
 */
static int queue_is_empty(struct queue_array *q) {
   if((q->read == q->write) && (q->read == -1)) {
      return 1;
   }
   return 0;
}
/**
 * @brief �½�һ������
 * @return ����ָ��
 */
struct queue_array *queue_array_new(void) {
    struct queue_array *temp = (struct queue_array *)malloc(sizeof(struct queue_array));
    if(!temp) {
        return NULL;
    }
    /* ����λ�ú�дδ֪������Ϊ-1 */
    temp->read = temp->write = -1;
    return temp;
}
/**
 * @brief ����push����
 * @param q ����ָ��
 * @param data Ҫ��ӵ�����
 */
void enqueue_array(struct queue_array *q, int data) {
   if(queue_is_empty(q)) {
       /* �������Ϊ�� �򽫶�д������Ϊ0 Ҫ��ʼд���� */
       q->read = q->write = 0;
   }else if((q->write + 1) % 3 == q->read) {
       /* ���������鹹�ɵĶ��У������������ʹ��ѭ������ĸ��� %3�е�3�������С */
       std::cout << "��������,�޷�д��\n";
       return;
   }else {
       /* ѭ��������� */
       q->write = (q->write + 1) % 3;
   }
   /* ��Ӹ�ֵ */
   q->buf[q->write] = data;
}
/**
 * @brief ����pop����
 * @param q ����ָ��
 * @return ���س��ӵ�ֵ
 */
int dequeue_array(struct queue_array *q) {
    if(queue_is_empty(q)){
        std::cout << "�����ǿյģ��޷���ȡ\n";
        return -1;
    } else if(q->read == q->write) {
        /* �������ֵ��ȣ������ö���Ϊ��ʼ״̬ */
        q->read = q->write = -1;
    } else {
        /* ѭ��������� */
        q->read = (q->read + 1) % 3;
    }
    return q->buf[q->read];
}
/**
 * @brief ɾ������
 * @param q ����ָ��
 */
void queue_array_del(struct queue_array *q) {
   if(q) {
       free(q);
   }
}
/**
 * @brief ��ӡ��������ֵ
 * @param q ����ָ��
 */
void queue_array_print(struct queue_array *q) {
    for(int i : q->buf) {
        printf("%d ", i);
    }
    printf("\n");
}
